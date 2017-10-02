//
//  SettingsViewController.swift
//  Alarm-ios-swift
//
//  Created by Rajat Bhageria on 4/15/17.
//  Copyright © 2017 LongGames. All rights reserved.
//

import Foundation

class SettingsViewController: UIViewController{
    
    @IBOutlet weak var demoButton: UIButton!
    
    @IBOutlet weak var demoFastClock: UIButton!
    
    @IBOutlet weak var demoColorShow: UIButton!
    
    let light: LightConnection = LightConnection();
    
    //For the demo sunrise light
    @IBAction func demo(_ sender: Any) {
        light.turnOnLight();
    }
    
    //For the demo fast clock
    @IBAction func demoFastClock(_ sender: Any) {
        light.demoFastClock();
    }
    
    //For the demo color show
    @IBAction func demoColorShow(_ sender: Any) {
        light.demoColorShow();
    }
   }
