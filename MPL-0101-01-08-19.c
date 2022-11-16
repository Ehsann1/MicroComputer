#include <mega32a.h>
#include <delay.h>

#define S_SEGMENT PORTD
#define EN_S_SEGMENT_3 PORTC.1 = 0
#define EN_S_SEGMENT_2 PORTC.2 = 0
#define EN_S_SEGMENT_1 PORTC.3 = 0

#define D_S_SEGMENT_3 PORTC.1 = 1
#define D_S_SEGMENT_2 PORTC.2 = 1
#define D_S_SEGMENT_1 PORTC.3 = 1

int number = 0 , turn_15_ms = 0;


char BCD(int num);
int split_number_one(int number);
int split_number_decimal(int number);
int split_number_hundreds(int number);

                                                      
void main(void){

    DDRC = 0XFF;
    DDRD = 0XFF; 
                         
    D_S_SEGMENT_1;
    D_S_SEGMENT_2;
    D_S_SEGMENT_3;
    
    while (1){       
    
    
    
    
    
        //EN_S_SEGMENT_1;                        
//        S_SEGMENT = BCD(9);
        EN_S_SEGMENT_1;
        S_SEGMENT = BCD(split_number_one(number));

        delay_ms(5);

        D_S_SEGMENT_1; 
        delay_ms(1);

        EN_S_SEGMENT_2;
        S_SEGMENT = BCD(split_number_decimal(number));

        delay_ms(5);   

        D_S_SEGMENT_2; 
        
        delay_ms(1);


        EN_S_SEGMENT_3;
        S_SEGMENT = BCD(split_number_hundreds(number));    

        delay_ms(5);           
        

                                
        D_S_SEGMENT_3;
                           
        delay_ms(1);

        turn_15_ms++;

        if(turn_15_ms > 69){
            turn_15_ms=0;
            number++;
        }      
        if(number>999){number=0;}
    }
}



int split_number_one(int number){
    return number % 10 ;
}
int split_number_decimal(int number){
    return (number % 100)/ 10 ;
}
int split_number_hundreds(int number){
    return (number % 1000) / 10 / 10;
}

char BCD(int num){
    switch (num){
        case 0: 
            // Code :0
            return 0XC0;
            break;
        case 1: 
            // Code :1
            return 0XF9;
            break;   
        case 2: 
            // Code :2
            return 0XA4;
            break;
        case 3: 
            // Code :3 
            return 0X30;
            break;
        case 4: 
            // Code :4
            return 0X99;
            break;
        case 5: 
            // Code :5
            return 0X92;
            break;
        case 6: 
            // Code :6 
            return 0X82;
            break;
        case 7: 
            // Code :7 
            return 0XF8;
            break;
        case 8: 
            // Code :8  
            return 0X80;
            break;
        case 9: 
            // Code :9  
            return 0X90;
            break;
    }
}