//
//  NextViewController.swift
//  SlackTime
//
//  Created by Kaho Matsumoto on 2018/01/12.
//  Copyright © 2018年 Kaho Matsumoto. All rights reserved.
//

import UIKit
import AVFoundation

class NextViewController: UIViewController, AVSpeechSynthesizerDelegate{
    @IBOutlet weak var dateTextField: UITextField!
    
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

