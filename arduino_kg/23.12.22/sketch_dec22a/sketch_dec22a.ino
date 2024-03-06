const int led[8] = {3,5,6,9,10,11};
void setup() {
  // put your setup code here, to run once:
}


//void loop() {
//  for(int i=0; i<6; i++){
//        for(int j=0; j<=10; j++){
//          analogWrite(led[i],j*20);
//          delay(100);
//        }
//        for(int j=10; j>=0; j--){
//          analogWrite(led[i], j*20);
//          delay(100);
//        }
//      }
//}
void loop() {
  for(int i=0; i<6; i++){
        for(int j=0; j<=255; j++){
          analogWrite(led[i],j);
          delay(4);
        }
      }
      for(int i=0; i<6; i++){
        analogWrite(led[i],0);
      }
}
