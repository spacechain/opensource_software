#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "spcmodprepare.h"
#include "spc_do_keep.h"
#include "spc_do_cmd.h"
#include "spc_start_mission.h"

#include "spc_start_work.h"

int spc_start_work(void)
//void spc_start_work(void)
{
	int ret = -1;
	ret = prepare_checkDataFile();
	if(-1 == ret)
	{
		printf("spc_start_work():");
		printf("No data file found.\n");
		return -1;
	}

	ret = prepare_processDataFile();	
	if(-1 == ret)
	{
		printf("spc_start_work():");
		printf("Failed to parse data file.\n");
		return -1;
	}

#if 1
	printf("\n\n");
	printf("SPACENODE:ready to process keep file.\n");
	spc_do_keep();
	printf("SPACENODE:keep file done.\n");
	printf("\n\n");

#endif 

#if 1
	
	printf("\n\n");
	printf("SPACENODE:ready to sign transactions.\n");
	spc_start_mission();
	printf("SPACENODE:sign transactions done.\n");
	printf("\n\n");
#endif 

#if 1
	printf("\n\n");
	printf("SPACENODE:ready to excute commands.\n");
	spc_do_cmd();
	printf("SPACENODE:excute commands done.\n");
	printf("\n\n");

	system(CLEANUPLOADDIRCMD);
	system(CLEANTXFILESDIRCMD);
#endif
	
	return 0;
}
