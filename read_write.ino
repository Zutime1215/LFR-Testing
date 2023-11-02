void line_follow() {
  reading();
  if (detect_sensor == 0) { 
    if (turn != 's') {
      (turn == 'r') ? motor(tsp, -tsp) : motor(-tsp, tsp);
      while( !s[2] && !s[3] ) reading();
      turn = 's';
    }
  }
  else if (detect_sensor <= 4 && detect_sensor > 0) { // Normal Line
    if (sensor == "00111100") {
      if (pos != 0) {
        (pos > 0) ? motor(-10*lsp, 10*rsp) : motor(10*lsp, -10*rsp);
        delay(abs(pos) * 5); // Need To Adjust.
      }
      motor(10*lsp, 10*rsp);
    }

  // For Right Side Turn
    else if (sensor == "00011100") motor(10*lsp, 9*rsp);
    
    else if (sensor == "00011110") {
      if (pos < 1) {pos = 1;}
      motor(10*lsp, 7*rsp);
    }
    else if (sensor == "00001110") {
      if (pos < 2) {pos = 2;}
      motor(10*lsp, 5*rsp);
    }
    else if (sensor == "00001111") {
      if (pos < 3) {pos = 3;}
      motor(10*lsp, 3*rsp);
    } 
    else if (sensor == "00000111") {
      if (pos < 4) {pos = 4;}
      motor(10*lsp, 1*rsp);
    }
    else if (sensor == "00000011") {
      if (pos < 5) {pos = 5;}
      motor(10*lsp, -1*rsp);
    }
    else if (sensor == "00000001") {
      if (pos < 6) {pos = 6;}
      motor(10*lsp, -3*rsp);
    }

  
  // For Left Side Turn
    else if (sensor == "00111000") motor(9*lsp, 10*rsp);

    else if (sensor == "01111000") {
       if (pos > -1) {pos = -1;}
       motor(7*lsp, 10*rsp);
    }
    else if (sensor == "01110000") {
      if (pos > -2) {pos = -2;}
      motor(5*lsp, 10*rsp);
    }
    else if (sensor == "11110000") {
      if (pos > -3) {pos = -3;}
      motor(3*lsp, 10*rsp);
    }
    else if (sensor == "11100000") {
      if (pos > -4) {pos = -4;}
      motor(1*lsp, 10*rsp);
    }
    else if (sensor == "11000000") {
      if (pos > -5) {pos = -5;}
      motor(-1*lsp, 10*rsp);
    }
    else if (sensor == "10000000") {
      if (pos > -6) {pos = -6;}
      motor(-3*lsp, 10*rsp);
    }

  }

  // else if (detect_sensor >=5 && detect_sensor <=7) { // Sharp Turn
  //   if ( (s[2]+s[3]) && s[0] && !s[5] ) turn = 'r'; // (s[2]==1 || s[3]==1) && s[0] == 1 && s[5] == 0
  //   if ( (s[2]+s[3]) && !s[0] && s[5] ) turn = 'l';
  // }

  // else if (detect_sensor == 8) { // T section, End Line
  //   delay(100); // Need To Adjust.
  //   reading();
  //   if (detect_sensor == 8) {      // Finish Line
  //     motor(0, 0);
  //     while (detect_sensor == 8) reading();
  //   }

  //   else if (detect_sensor == 0) turn = 'r'; // T Section. Use r or l in turn value.
  // }
}