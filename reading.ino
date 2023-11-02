void reading() {
  sensor = "";
  detect_sensor = 0;
  for (int i=0;i<num_of_sen;i++) {
    s[i] = analogRead(i);
    // ( s[i] > threshold ) ? s[i] = 1 : s[i] = 0; // Converts Analog to Digital
    // sensor =  sensor + String(s[i]);
    // detect_sensor += s[i];
  }
}