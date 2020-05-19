#include<stdio.h>
#include<stlib.h>
#include<setjmp.h>

void run_DART();

int all_linear, all_locs_definite, forcing_ok;
/*usage:function{ longjmp(x, caseNum);}
  		otherFunction{int i = 0; 
					  if((i = setjmp(x))==0) //try
					  	function();
					  else //catch(i)
					  	switch(i){case 1: case 2: default: }
					  }*/  		
jmp_buf x;

//Main
int main(){

	run_DART();

}

void run_DART(){

	all_linear = 1;
	all_locs_definite = 1;
	forcing_ok = 1;

	do{
		//TODO: stack = ⟨⟩; I⃗ = [] ; directed = 1 

		//TODO: while (directed) do
			//TODO: try (directed, stack, I⃗) = instrumented program(stack, I⃗)

			//TODO: catch any exception → 
				if (forcing_ok)
					printf("Bug found!\n");
					exit();
				else forcing_ok = 1
	}
	while(all_linear && all_locs_definite);

}
