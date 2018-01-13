//
//  NextViewController.swift
//  SlackTime
//
//  Created by Kaho Matsumoto on 2018/01/12.
//  Copyright © 2018年 Kaho Matsumoto. All rights reserved.
//

import UIKit
import DOCOMOSDKCommon
import DOCOMOSDKDialogue
import AVFoundation
import Speech


class NextViewController: UIViewController, AVSpeechSynthesizerDelegate{
    @IBOutlet weak var dateTextField: UITextField!
    
    @IBOutlet weak var AItalk: UILabel!
    
    @IBOutlet weak var Usertalk: UILabel!
    @IBOutlet weak var Userbtn: UIButton!
    
    private let speechRecognizer = SFSpeechRecognizer(locale: Locale(identifier: "ja-JP"))!
    private var recognitionRequest: SFSpeechAudioBufferRecognitionRequest?
    private var recognitionTask: SFSpeechRecognitionTask?
    private let audioEngine = AVAudioEngine()
    
    //雑談APIの設定
    //質問文問い合わせリクエスト
    var param: DialogueRequestParam!
    //雑談対話問い合わせ処理
    var dialogue: Dialogue!
    //回答データ
    var resultData: DialogueResultData!
    //エラー情報
    var sdkError: SdkError!
    //var talker: AVSpeechSynthesizer!
    //音声認識の結果、認識した文字列
    var voice = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        utter(str:"お疲れ様です　今日は何を飲みますか？")//メソッド呼び出し
        // Do any additional setup after loading the view.
        
        let datePicker = UIDatePicker()
        
        datePicker.datePickerMode = UIDatePickerMode.time
        
        datePicker.addTarget(self, action: #selector(NextViewController.datePickerValueChanged(sender:)), for: UIControlEvents.valueChanged)
        
        dateTextField.inputView = datePicker
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @objc func datePickerValueChanged(sender: UIDatePicker){
        
        let formatter = DateFormatter()
        
        formatter.dateStyle = DateFormatter.Style.none
        
        formatter.timeStyle = DateFormatter.Style.short
        
        dateTextField.text = formatter.string(from: sender.date)
        
        
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        view.endEditing(true)
    }
    
    func utter(str:String) {
        let speech = AVSpeechSynthesizer()
        let utterance = AVSpeechUtterance(string: str)//読み上げる文字
        utterance.voice = AVSpeechSynthesisVoice(language: "ja-JP")//読み上げの言語
        utterance.rate = 0.5 //読み上げの速度
        utterance.pitchMultiplier = 1.1 //声の高さ
        utterance.preUtteranceDelay = 0 //読み上げまでの待機時間
        utterance.postUtteranceDelay = 1 //読んだあとの待機時間
        speech.delegate = self
        
        speech.speak(utterance) //発話
    }
    
    // デリゲート
    // 読み上げ開始したときに呼ばれる
    internal func speechSynthesizer(_ synthesizer: AVSpeechSynthesizer, didStart utterance: AVSpeechUtterance) {
        print("読み上げ開始")
    }
    
    // 読み上げ終了したときに呼ばれる
    internal func speechSynthesizer(_ synthesizer: AVSpeechSynthesizer, didFinish utterance: AVSpeechUtterance) {
        print("読み上げ終了")
    }
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */
    
}

extension NextViewController: SFSpeechRecognizerDelegate {
    
    
    // 音声認識の可否が変更したときに呼ばれるdelegate
    func speechRecognizer(_ speechRecognizer: SFSpeechRecognizer, availabilityDidChange available: Bool) {
        if available {
            Userbtn.isEnabled = true
            Userbtn.setTitle("音声認識スタート", for: [])
        } else {
            Userbtn.isEnabled = false
            Userbtn.setTitle("音声認識ストップ", for: .disabled)
        }
    }
    public override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        requestRecognizerAuthorization()
    }
    
    private func requestRecognizerAuthorization() {
        // 認証処理
        SFSpeechRecognizer.requestAuthorization { authStatus in
            // メインスレッドで処理したい内容のため、OperationQueue.main.addOperationを使う
            OperationQueue.main.addOperation { [weak self] in
                guard let `self` = self else { return }
                
                switch authStatus {
                case .authorized:
                    self.Userbtn.isEnabled = true
                    
                case .denied:
                    self.Userbtn.isEnabled = false
                    self.Userbtn.setTitle("音声認識へのアクセスが拒否されています。", for: .disabled)
                    
                case .restricted:
                    self.Userbtn.isEnabled = false
                    self.Userbtn.setTitle("この端末で音声認識はできません。", for: .disabled)
                    
                case .notDetermined:
                    self.Userbtn.isEnabled = false
                    self.Userbtn.setTitle("音声認識はまだ許可されていません。", for: .disabled)
                }
            }
        }
    }
    
    private func startRecording() throws {
        
        refreshTask()
        
        let audioSession = AVAudioSession.sharedInstance()
        // 録音用のカテゴリをセット
        try audioSession.setCategory(AVAudioSessionCategoryRecord)
        try audioSession.setMode(AVAudioSessionModeMeasurement)
        try audioSession.setActive(true, with: .notifyOthersOnDeactivation)
        
        recognitionRequest = SFSpeechAudioBufferRecognitionRequest()
        
        guard let inputNode = audioEngine.inputNode as Optional else { fatalError("Audio engine has no input node") }
        guard let recognitionRequest = recognitionRequest else { fatalError("Unable to created a SFSpeechAudioBufferRecognitionRequest object") }
        
        // 録音が完了する前のリクエストを作るかどうかのフラグ。
        // trueだと現在-1回目のリクエスト結果が返ってくる模様。falseだとボタンをオフにしたときに音声認識の結果が返ってくる設定。
        recognitionRequest.shouldReportPartialResults = true
        
        recognitionTask = speechRecognizer.recognitionTask(with: recognitionRequest) { [weak self] result, error in
            
            
            guard let `self` = self else { return }
            
            var isFinal = false
            
            if let result = result {
                self.voice = result.bestTranscription.formattedString;
                self.Usertalk.text = self.voice
                isFinal = result.isFinal
            }
            // エラーがある、もしくは最後の認識結果だった場合の処理
            if error != nil || isFinal {
                self.audioEngine.stop()
                inputNode.removeTap(onBus: 0)
                
                self.recognitionRequest = nil
                self.recognitionTask = nil
                
                self.Userbtn.isEnabled = true
                self.Userbtn.setTitle("しゃべりかける", for: [])
                self.AI()
            }
        }
        
        // マイクから取得した音声バッファをリクエストに渡す
        let recordingFormat = inputNode.outputFormat(forBus: 0)
        inputNode.installTap(onBus: 0, bufferSize: 1024, format: recordingFormat) { (buffer: AVAudioPCMBuffer, when: AVAudioTime) in
            self.recognitionRequest?.append(buffer)
        }
        
        try startAudioEngine()
    }
    
    private func refreshTask() {
        if let recognitionTask = recognitionTask {
            recognitionTask.cancel()
            self.recognitionTask = nil
        }
    }
    private func startAudioEngine() throws {
        // startの前にリソースを確保しておく。
        audioEngine.prepare()
        
        try audioEngine.start()
        
        Usertalk.text = "どうぞ喋ってください。"
    }
    @IBAction func tappedStartButton(_ sender: AnyObject) {
        if audioEngine.isRunning {
            audioEngine.stop()
            recognitionRequest?.endAudio()
            Userbtn.isEnabled = false
            Userbtn.setTitle("停止中", for: .disabled)
        } else {
            try! startRecording()
            Userbtn.setTitle("しゃべるのをやめる", for: [])
        }
    }
    
    func AI(){
        //認証情報初期化
        //docomo Developer supportから取得したAPIキーを設定
        AuthApiKey.initializeAuth("79705866567a64506554337741335543613169765243677258464b6b544454687039492e69334f5072392e")
        
        param = DialogueRequestParam()
        dialogue = Dialogue()
        sdkError = SdkError()
        //talker = AVSpeechSynthesizer()
        //発話を設定
        param.utt = voice
        //APIのキャラクタ設定(デフォルト:ゼロ,20:桜子,30:ハヤテ)
        //param.character = 0
        
        /*
         雑談対話問い合わせ処理にデータを渡す.
         APIからは音声合成用情報が「resultData.yomi」に返ってくるので
         AVSpeechSynthesizerで読み上げる.
         コンテキストID(resultData.context)を使うことで継続した会話ができる.
         */
        dialogue.request(param, onComplete: { (resultData) -> Void in
            self.param.context = "\(resultData!.context)"
            self.AItalk.text = resultData!.yomi
            // let utterance = AVSpeechUtterance(string: "\(resultData!.yomi)")
            //utterance.voice = AVSpeechSynthesisVoice(language: "jp-JP")
            //utterance.rate = 0.2
            //utterance.pitchMultiplier = 1.4
            //self.talker.speak(utterance)
        }) { (sdkError) -> Void in
            print("\(sdkError!)")
        }
    }
}

