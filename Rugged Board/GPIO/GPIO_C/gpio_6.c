/* 
* write a program using 3 led and 1 switch conidtion :
* if we press the switch 1st time 1st led will turn on.
* if we press the switch 2nd time 2nd led will turn on.
* if we press the switch 3rd time 3rd led will turn on.
* after releasing switch leds will be in off state.
* also show the num of times switch pressed.
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define GPIO_EN "/sys/class/gpio/export"

#define LED1_DIR "/sys/class/gpio/PC13/direction"
#define LED1_VAL "/sys/class/gpio/PC13/value"

#define LED2_DIR "/sys/class/gpio/PC17/direction"
#define LED2_VAL "/sys/class/gpio/PC17/value"

#define LED3_DIR "/sys/class/gpio/PC19/direction"
#define LED3_VAL "/sys/class/gpio/PC19/value"


#define SW_DIR "/sys/class/gpio/PC12/direction"
#define SW_VAL "/sys/class/gpio/PC12/value"

int led1_fd,led2_fd,led3_fd,sw_fd;
char gpio_buf[30];
int led1_num = 77,led2_num = 81,led3_num = 83,sw_num = 76;

void led_init()
{
	//led export
	led1_fd = open(GPIO_EN,O_WRONLY);
	if(led1_fd < 0)
	{
		printf("Unable to open file %s \n",GPIO_EN);
		exit(0);
	}
	printf("Enabled LED\n");
	sprintf(gpio_buf,"%d",led1_num);
	write(led1_fd,gpio_buf,strlen(gpio_buf));
	close(led1_fd);

        //led export
        led2_fd = open(GPIO_EN,O_WRONLY);
        if(led2_fd < 0)
        {
                printf("Unable to open file %s \n",GPIO_EN);
                exit(0);
        }
        printf("Enabled LED\n");
        sprintf(gpio_buf,"%d",led2_num);
        write(led2_fd,gpio_buf,strlen(gpio_buf));
        close(led2_fd);

        //led export
        led3_fd = open(GPIO_EN,O_WRONLY);
        if(led3_fd < 0)
        {
                printf("Unable to open file %s \n",GPIO_EN);
                exit(0);
        }
        printf("Enabled LED\n");
        sprintf(gpio_buf,"%d",led3_num);
        write(led3_fd,gpio_buf,strlen(gpio_buf));
        close(led3_fd);


	//sw export
        sw_fd = open(GPIO_EN,O_WRONLY);
        if(sw_fd < 0)
        {
                printf("Unable to open file %s \n",GPIO_EN);
                exit(0);
        }
        printf("Enabled SW\n");
        sprintf(gpio_buf,"%d",sw_num);
        write(sw_fd,gpio_buf,strlen(gpio_buf));
        close(sw_fd);

	//led direction
	printf("configuring LED 1 direction \n");
	led1_fd = open(LED1_DIR,O_WRONLY);
	if(led1_fd < 0)
	{
		printf("Unable to open the file %s",LED1_DIR);
		exit(0);
	}
	write(led1_fd,"out",3);
	close(led1_fd);

        printf("configuring LED 2 direction \n");
        led2_fd = open(LED2_DIR,O_WRONLY);
        if(led2_fd < 0)
        {
                printf("Unable to open the file %s",LED2_DIR);
                exit(0);
        }
        write(led2_fd,"out",3);
        close(led2_fd);

        printf("configuring LED 3 direction \n");
        led3_fd = open(LED3_DIR,O_WRONLY);
        if(led3_fd < 0)
        {
                printf("Unable to open the file %s",LED3_DIR);
                exit(0);
        }
        write(led3_fd,"out",3);
        close(led3_fd);


        //sw direction
        printf("configuring LED direction \n");
        sw_fd = open(SW_DIR,O_WRONLY);
        if(sw_fd < 0)
        {
                printf("Unable to open the file %s",SW_DIR);
                exit(0);
        }
        write(sw_fd,"in",2);
        close(sw_fd);

	//led value
	printf("set value into LED \n");

	led1_fd = open(LED1_VAL,O_WRONLY);
	if(led1_fd < 0)
	{
		printf("Unable to open file %s",LED1_VAL);
		exit(0);
	}

        led2_fd = open(LED2_VAL,O_WRONLY);
        if(led2_fd < 0)
        {
                printf("Unable to open file %s",LED2_VAL);
                exit(0);
        }

	led3_fd = open(LED3_VAL,O_WRONLY);
        if(led3_fd < 0)
        {
                printf("Unable to open file %s",LED3_VAL);
                exit(0);
        }


	sw_fd = open(SW_VAL,O_RDONLY);
        if(sw_fd < 0)
        {
                printf("Unable to open file %s",SW_VAL);
                exit(0);
        }
}
int main()
{
	char buf[2];
	led_init();
	int flag=0,count=0;
	printf("Running program");
	write(led1_fd,"1",1);
        write(led2_fd,"1",1);
        write(led3_fd,"1",1);

	while(1)
	{
		lseek(sw_fd,0,SEEK_SET);
		read(sw_fd , buf, 1);
		if(buf[0] == '0')
		{
		flag=flag+1;
		count = count +1;
		printf("no to times button pressed %d \n",count);	
		usleep(500000);
		}
	
		switch (flag){
			case 1:
				write(led1_fd,"0",1);
				break;
			case 2: 
				write(led2_fd,"0",1);
				break;
			case 3:
				write(led3_fd,"0",1);
				break;
			case 4: 
				write(led1_fd,"1",1);
				write(led2_fd,"1",1);
				write(led3_fd,"1",1);
				flag =0;
				break;
				}

	}
}


