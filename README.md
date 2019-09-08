Digispark

Payload: clippy.exe

Decsription: Uses powershell to download payload in "startup" folder as to load on startup. User cannot stop payload as it will run in memory and Windows will not allow user to delete payload. Powershell executes "clippy.exe" and "clippy.vbs" as administrator from webserver. Disable Windows Defender as to not find payload. 

clippy.exe: Fun joke program creates an annoying Clippy/Clippit Office Assistant popup form Microsoft Word (version 97 to 2003). Popup every 60 sec created by http://rjlpranks.com/pranks/clippy/ 

clippy.vbs: Fake windows error to deter user from closing powershell. 

Created by Tyler Smith - http://DataDucks.3utilities.com/forum (Forums) - DataDucks.Web.Development@gmail.com
_____________________________________________________________________________________________________________
How to upload:

Upload sketch_aug12a.ino to Digispark.
Put "clippy.exe", "clippy.txt", "clippy.vbs" in C:/xampp/htdocs/ (or wherever else your xampp host is located)
Or put them in your host server if you dont have xampp.
