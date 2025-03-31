/* 
 *Write a Program using 1 led and 1 switch conditions:
 *if we press the switch 1st time led will toggle 1 time
 *if we press the switch 2nd time led will toggle 2 times.
 *if we press the switch 3rd time led will toggle 3 times.
 *and this should be in a loop.
 *also print the number of times switch pressed.
 */
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define GPIO_EN "/sys/class/gpio/export"

#define LED_DIR "/sys/class/gpio/PC13/direction"
#define LED_VAL "/sys/class/gpio/PC13/value"

#define SW_DIR "/sys/class/gpio/PC12/direction"
#define SW_VAL "/sys/class/gpio/PC12/value"

int led_fd,sw_fd;
char gpio_buf[30];
int led_num = 77,sw_num = 76;

void led_init()
{
	//led export
	led_fd = open(GPIO_EN,O_WRONLY);
	if(led_fd < 0)
	{
		printf("Unable to open file %s \n",GPIO_EN);
		exit(0);
	}
	printf("Enabled LED\n");
	sprintf(gpio_buf,"%d",led_num);
	write(led_fd,gpio_buf,strlen(gpio_buf));
	close(led_fd);

	//sw export
        sw_fd = open(GPIO_EN,O_WRONLY);
        if(led_fd < 0)
        {
                printf("Unable to open file %s \n",GPIO_EN);
                exit(0);
        }
        printf("Enabled SW\n");
        sprintf(gpio_buf,"%d",sw_num);
        write(sw_fd,gpio_buf,strlen(gpio_buf));
        close(sw_fd);

	//led direction
	printf("configuring LED direction \n");
	led_fd = open(LED_DIR,O_WRONLY);
	if(led_fd < 0)
	{
		printf("Unable to open the file %s",LED_DIR);
		exit(0);
	}
	write(led_fd,"out",3);
	close(led_fd);

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

	led_fd = open(LED_VAL,O_WRONLY);
	if(led_fd < 0)
	{
		printf("Unable to open file %s",LED_VAL);
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
	int count=0;
	printf("Running program\n");
	write(led_fd,"1",1);
	while(1)
	{
		lseek(sw_fd,0,SEEK_SET);
		read(sw_fd , buf, 1);
		if(buf[0] == '0')
		{
			count = count +1;
			printf("Number to times pressed : %d\n",count);
			for(int i = 0; i<count; i++)
			{
			write(led_fd,"0",1);
			sleep(1);
			write(led_fd,"1",1);
			sleep(1);
			}
			//printf("Number to times pressed : %d",count);
		}
		
	}
}


