#include "main.h"
Serial pc(USBTX, USBRX,57600); // tx, rx
Serial IMU(PC_10, PC_11,57600); // tx, rx

int main() {
    int state = 0;
    //posture imu;
    pc.printf("Hello World!\n");
    while(1) {
                switch(state){
                case 0:
                if(IMU.getc() == 0x3A)
                    {state ++;
                    pc.putc('1');}
                else state = 0;
                break;
                case 1:
                if(IMU.getc() == 0x01)
                    {state ++;
                    pc.putc('2');}
                else state = 0;
                break;
                case 2:
                if(IMU.getc() == 0x00)
                    {state ++;
                    pc.putc('3');}
                else state = 0;
                break;
                case 3:
                if(IMU.getc() == 0x09)
                    {state ++;
                    pc.putc('4');}
                else state = 0;
                break;
                case 4:
                if(IMU.getc() == 0x00)
                    {state ++;
                    pc.putc('5');}
                else state = 0;
                break;
                case 5:
                if(IMU.getc() == 0x38)//56 bytes
                    {state ++;
                    pc.putc('6');}
                else state = 0;
                break;
                case 6:
                if(IMU.getc() == 0x00)//56 bytes
                    {state ++;
                    pc.putc('7');}
                else state = 0;
                break;
                case 7:
                //pc.printf("good\n");
                    for(int k=0;k<56;k++)
                    {
                    posture.data[k] = IMU.getc();
                    pc.putc(posture.data[k]);
                    state++;
                     }
                //pc.printf("\n'%d'\n",state);
                pc.printf("\nTimestamp:'%f'",posture.valF[0]);
                pc.printf("\nGyroscope:'%f','%f','%f'",posture.valF[1],posture.valF[2],posture.valF[3]);
                pc.printf("\nAccelerometer: '%f','%f','%f'",posture.valF[4],posture.valF[5],posture.valF[6]);
                pc.printf("\nMagnetometer: '%f','%f','%f'",posture.valF[7],posture.valF[8],posture.valF[9]);
                pc.printf("\nQuaternion: '%f','%f','%f'",posture.valF[10],posture.valF[11],posture.valF[12]);
                state = 0;
                break;
                default:
                state = 0;
                break;
                }
                }
            }
        


