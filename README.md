# arduino-melodies
Melodies for Arduino personally played and converted

These melodies were generated with a midi keyboard and converted for inclusion in a project based on an ESP8266. They are designed to be played in a loop, so if you start over again, the melody doesn't stop. Since they were played with different BPM values, I proceeded to report the exact value for each of them.

The "player_example.ino" file shows an example of how melodies can be implemented in an Arduino-based project, but if you want to try them online, you can use the wokwi site

Instructions for use:

  1) Go to https:wokwi.com/ and select the box with Arduino (Uno, Mega, Nano);
  2) Scroll down to the "Start from Scratch" section and select the "Arduino Uno" box;
  3) Click the (+) button on the Arduino board;
  4) Write "buzzer" in the search text (without double quotes) and click on the entry found. The buzzer will appear on the card;
  5) Position the mouse cursor over pin 8 of the Arduino board and click once;
  6) Position the mouse cursor at the end of the red buzzer cable and click a second time;
  7) Position the mouse cursor over the GND pin of the Arduino board and click once;
  8) Position the mouse cursor at the end of the black buzzer cable and click a second time;
  9) Delete all the code in the left window;
 10) Paste the code from the "player_example.ino" file into the window;
 11) Replace entire block "
      const NoteStep melody[] = {
      ...
      }
     " with the same as one of the present melodies;
 12) Press the Play button. If the message "Failed to fetch" appears, press the Play button again.
