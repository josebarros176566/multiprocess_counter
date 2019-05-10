

       #include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>



int main (){
	
	

        int* vetor ;
	int protection = PROT_READ | PROT_WRITE;
  	int visibility = MAP_SHARED | MAP_ANON;
	int soma=0;
	//soma= (int*) mmap(NULL, sizeof(int)*1, protection, visibility, 0, 0);
	//*soma=0;
	//char st[80];

	 unsigned int n[80],a,b;
	pid_t pid[2];
	int i=0,j=0,c,e,k;
	
	
	do{
		k= scanf("%u",&a);
		n[j]=a;
		j++;
	}while(k!=EOF);


	/*while(st[i]!='\0'){
		a=atoi(st[i]);
		n[j]=a;
		j++;
		i++;
		while(st[i]=' ' )
			i++;
	}*/
	j=j-2;
	i=0;
/*for(k=0;k<=j;k++){
	printf("%d\n",n[k]);

}*/
vetor=(int*)mmap(NULL,j,protection,visibility,-1,0);

while(i<=j){
	//printf("%d\n",i);
	if((j-i)>=3){
			//printf("entrada1\n");
		for(e=0;e<3;e++){
			a=n[i];
			i++;
			pid[e]=fork();
			if(pid[e]==0){
				c=0;
				for(b=2;b<a;b++){
					if(a%b==0)
					c=1;
				}
				if(c==0)
					vetor[i-1]=1;
				else vetor[i-1]=0;
				if(a==0||a==1)			
					vetor[i-1]=0;				
				exit(0);
			}	
		}
		for(e=0;e<3;e++)
			waitpid(pid[e], NULL, 0);
				
	}
	else if((j-i)==2){
		//printf("entrada2\n");		
		for(e=0;e<2;e++){
			a=n[i];
			i++;
			pid[e]=fork();
			if(pid[e]==0){
				c=0;
				for(b=2;b<a;b++){
					if(a%b==0)
					c=1;
				}
				if(c==0)
					vetor[i-1]=1;
				else vetor[i-1]=0;
				if(a==0||a==1)			
					vetor[i-1]=0;				
				exit(0);
			}	
		}
		for(e=0;e<2;e++)
			waitpid(pid[e], NULL, 0);
	}
	else if((j-i)==1){
			//printf("entrada3\n");
		for(e=0;e<1;e++){
			a=n[i];
			i++;
			pid[e]=fork();
			if(pid[e]==0){
				c=0;
				for(b=2;b<a;b++){
					if(a%b==0)
					c=1;
				}
				if(c==0)
					vetor[i-1]=1;
				else vetor[i-1]=0;
					
				if(a==0||a==1)			
					vetor[i-1]=0;				
				exit(0);
			}	
		}
		for(e=0;e<1;e++)
			waitpid(pid[e], NULL, 0);
	}
	else if ((j-i)==0){
		break;
	}
	
}
	
	
	for(k=0;k<=i;k++)
		soma=soma+vetor[k];

	 printf("%d\n",soma);
	
	
	
}
	
 	

