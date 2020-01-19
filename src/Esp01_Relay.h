#ifdef Esp01_Relay

void setupRelay(){
    pinMode(Esp01_Pin, OUTPUT);
    digitalWrite(Esp01_Pin, LOW);
}

void setRelay(short i){
    digitalWrite(Esp01_Pin, i);
}

void relaySendState(){
    
}

void relayCallback(){
    

    relaySendState();
}




#endif