//
//  LightConnection.swift
//  Alarm-ios-swift
//
//  Created by Rajat Bhageria on 4/15/17.
//  Copyright © 2017 LongGames. All rights reserved.
//

import Foundation

class LightConnection{
    func turnOnLight(){
        print("turnOnLight() called")
        sendCommand(command: "sunrise")
    }
    
    func demoFastClock(){
        print("demoFastClock() called")
        sendCommand(command: "settime")
    }
    
    func demoColorShow(){
        print("demoColorShow() called")
        sendCommand(command: "whitecolor")
    }
    
    func demoFull(){
        print("demoFull() called")
        sendCommand(command: "demo")
    }
    
    func sendCommand(command: String) {
        print(command + "called on Light")
        var request = URLRequest(url: URL(string: "https://api.particle.io/v1/devices/43002a000347343337373738/led?access_token=7c85328e2dde3f883825c23866458ec549daf707")!)
        request.httpMethod = "POST"
        let postString = "arg=" + command
        request.httpBody = postString.data(using: .utf8)
        let task = URLSession.shared.dataTask(with: request) { data, response, error in
            guard let data = data, error == nil else {                                                 // check for fundamental networking error
                return
            }
            
            if let httpStatus = response as? HTTPURLResponse, httpStatus.statusCode != 200 {           // check for http errors
                print("statusCode should be 200, but is \(httpStatus.statusCode)")
            }
            
            let responseString = String(data: data, encoding: .utf8)
        }
        task.resume()
    }
}
