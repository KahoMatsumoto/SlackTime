//
//  ViewController.swift
//  SlackTime
//
//  Created by Kaho Matsumoto on 2018/01/12.
//  Copyright © 2018年 Kaho Matsumoto. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBAction func unwindToTop(segue: UIStoryboardSegue) {
        
    }

    @IBAction func start(_ sender: Any) {
        
        let alertController = UIAlertController(
            title: "スマホをセットしてください",
            message: "",
            preferredStyle: .alert
        )
        
        //「OK」を押すと次のページに遷移
        let startAction = UIAlertAction(title: "OK", style: .default) { (action:UIAlertAction!) -> Void in
            let next = self.storyboard?.instantiateViewController(withIdentifier: "nextView")
            self.present(next!,animated: true, completion: nil)
        }
        
        alertController.addAction(startAction)
        present(alertController, animated: true, completion: nil)
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

