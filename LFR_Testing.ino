#define lmf 2 // InB
#define lmb 6 // InA
#define lms 9  // EnA
#define rmf 5 // InC
#define rmb 4 // InD
#define rms 11 // EnB

int num_of_sen=8, s[8], base[8]={1,2,4,8,16,32,64,128};
int detect_sensor, threshold=680;
String sensor;

int sensor_pid, avg_value, position[8]={-4,-3,-2,-1,1,2,3,4};
int lbase = 200, rbase = 200;
int lmotor, rmotor;
int kp = 50, kd=1000;
// float ki = 0.01;
int PID;
int error, last_error;

int pos; // Turn Newar smy er biporite Force create kore.
char turn = 's';

int left_max_speed = 170, right_max_speed = 180; // Left Motor is tiny fast
int lsp = left_max_speed/10, rsp = right_max_speed/10, tsp = 180;

void setup() {
  Serial.begin(9600);

  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);

}

void loop() {

  reading();

  for (int i=0;i<num_of_sen;i++) {
    Serial.print(String(s[i]) + " ") ;
  }
  Serial.println("\n");
  // Serial.println(sensor);
  // Serial.println(detect_sensor);

  delay(800);
  
}