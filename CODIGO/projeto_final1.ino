#define  led1       10            
#define  led2       11            
#define  led3       12            
#define  ledPortao  9             
#define  botao1     5             
#define  botao2     6             
#define  botao3     7             
#define  botaoPortao 4            
#define  piezo      8             

#define  nota_C4  262             
#define  nota_E4  330             
#define  nota_G4  392             
#define  nota_A4  440             

void output1();
void output2();
void output3();
void outputPortao();
void memoryClear();
void start();
void gameOver();
void complete();
void check(byte number);

byte memory[20];                
byte count = 0x00;              
int level = 0x01;               
boolean wait = 0x00;            

void setup() {  
    pinMode(led1, OUTPUT);            
    pinMode(led2, OUTPUT);            
    pinMode(led3, OUTPUT);            
    pinMode(ledPortao, OUTPUT);       
    pinMode(botao1, INPUT_PULLUP);    
    pinMode(botao2, INPUT_PULLUP);    
    pinMode(botao3, INPUT_PULLUP);    
    pinMode(botaoPortao, INPUT_PULLUP);
    pinMode(piezo, OUTPUT);           
    
    digitalWrite(led1, LOW);          
    digitalWrite(led2, LOW);          
    digitalWrite(led3, LOW);          
    digitalWrite(ledPortao, LOW);     
    noTone(piezo);                    
        
    memoryClear();                    
} 

void loop() {
    start();                  

    for(int i = 0; i < level; i++) {
        byte rand = random(1, 5); 
        memory[i] = rand;         
        
        switch(rand) {            
            case 0x01: output1(); break;  
            case 0x02: output2(); break;  
            case 0x03: output3(); break;  
            case 0x04: outputPortao(); break; 
        } 
        
        wait = 0x01;                     
    } 

    while(wait) {                        
        if(!digitalRead(botao1)) {       
            output1();                   
            check(0x01);                 
        } 

        if(!digitalRead(botao2)) {       
            output2();                   
            check(0x02);                 
        } 

        if(!digitalRead(botao3)) {       
            output3();                   
            check(0x03);                 
        } 

        if(!digitalRead(botaoPortao)) {  
            outputPortao();              
            check(0x04);                 
        } 
    } 
} 

void output1() {   
    digitalWrite(led1, HIGH);
    tone(piezo, nota_C4);
    delay(300);
    digitalWrite(led1, LOW);
    noTone(piezo);
    delay(300);
} 

void output2() {   
    digitalWrite(led2, HIGH);
    tone(piezo, nota_E4);
    delay(300);
    digitalWrite(led2, LOW);
    noTone(piezo);
    delay(300);
} 

void output3() {  
    digitalWrite(led3, HIGH);
    tone(piezo, nota_G4);
    delay(300);
    digitalWrite(led3, LOW);
    noTone(piezo);
    delay(300);
} 

void outputPortao() {  
    digitalWrite(ledPortao, HIGH);
    tone(piezo, nota_A4);
    delay(300);
    digitalWrite(ledPortao, LOW);
    noTone(piezo);
    delay(300);
} 

void start() {    
    for(int j=0; j<5; j++) {  
        digitalWrite(led1, HIGH); 
        digitalWrite(led2,  LOW);
        digitalWrite(led3,  LOW);
        digitalWrite(ledPortao, LOW);
        delay(100);
        digitalWrite(led1,  LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3,  LOW);
        digitalWrite(ledPortao, LOW);
        delay(100);
        digitalWrite(led1,  LOW); 
        digitalWrite(led2,  LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(ledPortao, LOW);
        delay(100);
        digitalWrite(led1,  LOW); 
        digitalWrite(led2,  LOW);
        digitalWrite(led3,  LOW);
        digitalWrite(ledPortao, HIGH);
        delay(100);
    } 
    
    digitalWrite(ledPortao, LOW); 
    delay(500); 
} 

void gameOver() {    
    start();        
    level = 0x01;   
    wait  = 0x00;   
    count = 0x00;   
} 

void memoryClear() {        
    for(int i = 0; i < 20; i++) memory[i] = 0; 
} 

void complete() {             
    if(level == count) {      
        wait  = 0x00;         
        count = 0x00;         
        memoryClear();        
        level++;              
    } 
} 

void check(byte number) {           
    if(memory[count] == number) {   
        count++;                    
        complete();                 
    } 
    else gameOver(); 
} 
