import processing.core.PApplet;
import processing.serial.*;

Serial myPort;
String my_port = Serial.list()[2];
float xx, yy, zz;  // Original angles
float xx_mod, yy_mod, zz_mod;  // Modified angles

void setup(){
  myPort = new Serial(this, my_port, 9600);
  myPort.bufferUntil('\n');

  smooth();
  SecondApplet SA = new SecondApplet();
  PApplet.runSketch(new String[] {"DataWin"},SA);
  size(600, 600, P3D); 
}

void draw(){
  background(0);
  pushMatrix();
  translate(width / 2, height / 2);
  rotateX(xx);  // pitch
  rotateY(zz);  // yaw
  rotateZ(yy);  // roll
  box(72, 20, 180);
  popMatrix();
}


public class SecondApplet extends PApplet {
  
  void settings(){
    size(600, 600, P3D);
  }
  void draw(){
    background(0);
    pushMatrix();
    translate(width / 2, height / 2);
    rotateX(xx_mod);  // modified pitch
    rotateY(zz_mod);  // modified yaw
    rotateZ(yy_mod);  // modified roll
    box(72, 20, 180);
    popMatrix();
    
  }
  
}
void serialEvent(Serial myPort) {
  String myString = myPort.readStringUntil('\n');
  myString = trim(myString);
  float sensors[] = float(split(myString, ':'));

  // Update original angles
  xx = sensors[0];
  yy = sensors[1];
  zz = sensors[2];


  xx_mod = sensors[3];
  yy_mod = sensors[4];
  zz_mod = sensors[5];

  println("Original - roll: " + degrees(xx) + " pitch: " + degrees(yy) + " yaw: " + degrees(zz));
  println("Modified - roll: " + degrees(xx_mod) + " pitch: " + degrees(yy_mod) + " yaw: " + degrees(zz_mod));
}
