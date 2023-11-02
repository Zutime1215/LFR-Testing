void pid_reading() {
  sensor = "";
  detect_sensor = 0;
  for (int i=0;i<num_of_sen;i++) {
    s[i] = analogRead(i);
    ( s[i] > threshold ) ? s[i] = 1 : s[i] = 0; // Converts Analog to Digital
    sensor_pid += s[i]*position[i];
    detect_sensor += s[i];
  }
  if (detect_sensor) avg_value = sensor_pid/detect_sensor;
}