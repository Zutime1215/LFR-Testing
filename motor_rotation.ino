void motor(int l, int r){
  if (l > 0) {
    digitalWrite(lmf, 1);
    digitalWrite(lmb, 0);   
  }
  else {
    digitalWrite(lmf, 0);
    digitalWrite(lmb, 1);
  }
  
  if (r > 0) {
    digitalWrite(rmf, 1);
    digitalWrite(rmb, 0);   
  }
  else {
    digitalWrite(rmf, 0);
    digitalWrite(rmb, 1);
  }

  l = abs(l); r = abs(r);

  if (l > left_max_speed) l = left_max_speed;
  if (r > right_max_speed) r = right_max_speed;
  
  analogWrite(lms, l);
  analogWrite(rms, r);
}