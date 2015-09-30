#define TIMES 1024 * 1024 * 128

__kernel void plus_1d(
	__global int* input,
	__global int* output,
	const unsigned int count)
  {
	unsigned int global_index = get_global_id(0);
	if(global_index < count)
	  {
		int s = output[global_index];
		int a = input[global_index];
		long i;
		for(i = 0; i < TIMES; i++)
		  {
			s = s + a;
		  }
		printf("count: %d\n", s);
		output[global_index] = s;
	  }
  }
;
