/* Process model C form file: fifo_fair_owl_old.pr.c */
/* Portions of this file copyright 1986-2008 by OPNET Technologies, Inc. */



/* This variable carries the header into the object file */
const char fifo_fair_owl_old_pr_c [] = "MIL_3_Tfile_Hdr_ 145A 30A op_runsim 7 55BCF3E0 55BCF3E0 1 OWL-1 Liliana 0 0 none none 0 0 none 0 0 0 0 0 0 0 0 1e80 8                                                                                                                                                                                                                                                                                                                                                                                                          ";
#include <string.h>



/* OPNET system definitions */
#include <opnet.h>



/* Header Block */

#include "ip_addr_v4.h"
#include "ip_dgram_sup.h"

#define CLEAN_ADDR 3232235776

#define ARRIVAL     op_intrpt_type () == OPC_INTRPT_STRM
#define SERVICE     op_intrpt_type () == OPC_INTRPT_SELF
//#define CLOSE (op_intrpt_type()==OPC_INTRPT_ENDSIM)
int ctr1=0;
int ctr2=0;

double  g_loss=0;
double  g_loss2=0;
wait=0;
loss_ctr_ant=0;
 

/* End of Header Block */

#if !defined (VOSD_NO_FIN)
#undef	BIN
#undef	BOUT
#define	BIN		FIN_LOCAL_FIELD(_op_last_line_passed) = __LINE__ - _op_block_origin;
#define	BOUT	BIN
#define	BINIT	FIN_LOCAL_FIELD(_op_last_line_passed) = 0; _op_block_origin = __LINE__;
#else
#define	BINIT
#endif /* #if !defined (VOSD_NO_FIN) */



/* State variable definitions */
typedef struct
	{
	/* Internal state tracking for FSM */
	FSM_SYS_STATE
	/* State Variables */
	Objid	                  		my_id_queue                                     ;
	double	                 		bit_rate                                        ;
	int	                    		ip_address                                      ;
	int	                    		loss_ctr                                        ;
	double	                 		loss_avg                                        ;
	int	                    		loss_avg_ctr                                    ;
	int	                    		packet_size_bits                                ;
	int	                    		number_of_packets                               ;
	int	                    		total_loss_ctr                                  ;
	IpT_Dgram_Fields*	      		pkt_fields_ptr                                  ;
	double	                 		sched_ptr                                       ;
	double	                 		pkt_proc_time                                   ;
	int	                    		time200                                         ;
	int	                    		time201                                         ;
	double	                 		num_pkts                                        ;
	int	                    		last_pkt_destroyed                              ;
	int	                    		ip_address_send                                 ;
	int	                    		pkt_destroy                                     ;
	int	                    		loss                                            ;
	int	                    		loss_ctr_ant                                    ;
	int	                    		wait                                            ;
	int	                    		loss_ctr2                                       ;
	double	                 		loss_avg2                                       ;
	int	                    		loss_avg_ctr2                                   ;
	int	                    		pkt_destroy2                                    ;
	int	                    		wait2                                           ;
	int	                    		loss2                                           ;
	int	                    		loss_ctr_ant2                                   ;
	} fifo_fair_owl_old_state;

#define my_id_queue             		op_sv_ptr->my_id_queue
#define bit_rate                		op_sv_ptr->bit_rate
#define ip_address              		op_sv_ptr->ip_address
#define loss_ctr                		op_sv_ptr->loss_ctr
#define loss_avg                		op_sv_ptr->loss_avg
#define loss_avg_ctr            		op_sv_ptr->loss_avg_ctr
#define packet_size_bits        		op_sv_ptr->packet_size_bits
#define number_of_packets       		op_sv_ptr->number_of_packets
#define total_loss_ctr          		op_sv_ptr->total_loss_ctr
#define pkt_fields_ptr          		op_sv_ptr->pkt_fields_ptr
#define sched_ptr               		op_sv_ptr->sched_ptr
#define pkt_proc_time           		op_sv_ptr->pkt_proc_time
#define time200                 		op_sv_ptr->time200
#define time201                 		op_sv_ptr->time201
#define num_pkts                		op_sv_ptr->num_pkts
#define last_pkt_destroyed      		op_sv_ptr->last_pkt_destroyed
#define ip_address_send         		op_sv_ptr->ip_address_send
#define pkt_destroy             		op_sv_ptr->pkt_destroy
#define loss                    		op_sv_ptr->loss
#define loss_ctr_ant            		op_sv_ptr->loss_ctr_ant
#define wait                    		op_sv_ptr->wait
#define loss_ctr2               		op_sv_ptr->loss_ctr2
#define loss_avg2               		op_sv_ptr->loss_avg2
#define loss_avg_ctr2           		op_sv_ptr->loss_avg_ctr2
#define pkt_destroy2            		op_sv_ptr->pkt_destroy2
#define wait2                   		op_sv_ptr->wait2
#define loss2                   		op_sv_ptr->loss2
#define loss_ctr_ant2           		op_sv_ptr->loss_ctr_ant2

/* These macro definitions will define a local variable called	*/
/* "op_sv_ptr" in each function containing a FIN statement.	*/
/* This variable points to the state variable data structure,	*/
/* and can be used from a C debugger to display their values.	*/
#undef FIN_PREAMBLE_DEC
#undef FIN_PREAMBLE_CODE
#define FIN_PREAMBLE_DEC	fifo_fair_owl_old_state *op_sv_ptr;
#define FIN_PREAMBLE_CODE	\
		op_sv_ptr = ((fifo_fair_owl_old_state *)(OP_SIM_CONTEXT_PTR->_op_mod_state_ptr));


/* No Function Block */

#if !defined (VOSD_NO_FIN)
enum { _op_block_origin = __LINE__ };
#endif

/* Undefine optional tracing in FIN/FOUT/FRET */
/* The FSM has its own tracing code and the other */
/* functions should not have any tracing.		  */
#undef FIN_TRACING
#define FIN_TRACING

#undef FOUTRET_TRACING
#define FOUTRET_TRACING

#if defined (__cplusplus)
extern "C" {
#endif
	void fifo_fair_owl_old (OP_SIM_CONTEXT_ARG_OPT);
	VosT_Obtype _op_fifo_fair_owl_old_init (int * init_block_ptr);
	void _op_fifo_fair_owl_old_diag (OP_SIM_CONTEXT_ARG_OPT);
	void _op_fifo_fair_owl_old_terminate (OP_SIM_CONTEXT_ARG_OPT);
	VosT_Address _op_fifo_fair_owl_old_alloc (VosT_Obtype, int);
	void _op_fifo_fair_owl_old_svar (void *, const char *, void **);


#if defined (__cplusplus)
} /* end of 'extern "C"' */
#endif




/* Process model interrupt handling procedure */


void
fifo_fair_owl_old (OP_SIM_CONTEXT_ARG_OPT)
	{
#if !defined (VOSD_NO_FIN)
	int _op_block_origin = 0;
#endif
	FIN_MT (fifo_fair_owl_old ());

		{
		/* Temporary Variables */
		Packet          *pkt;
		Packet			*q_pkt;
		int				n;
		int				ctr200;
		int				ctr201;
		int				pos_0;
		int				pos_1;
		int				ins_code;
		/* End of Temporary Variables */


		FSM_ENTER ("fifo_fair_owl_old")

		FSM_BLOCK_SWITCH
			{
			/*---------------------------------------------------------*/
			/** state (INS_TAIL) enter executives **/
			FSM_STATE_ENTER_FORCED (0, "INS_TAIL", state0_enter_exec, "fifo_fair_owl_old [INS_TAIL enter execs]")
				FSM_PROFILE_SECTION_IN ("fifo_fair_owl_old [INS_TAIL enter execs]", state0_enter_exec)
				{
				//FILE *fr;
				
				pkt_destroy=0;
				pkt_destroy2=0;
				//printf("Entered INS_TAIL State\n");
				
				/* a new packet has arrived; acquire it */
				pkt = op_pk_get (op_intrpt_strm ());
				//op_pk_nfd_access (pkt, "fields", &pkt_fields_ptr);
				//ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;
				
				ins_code = op_subq_pk_insert (0, pkt, OPC_QPOS_TAIL);
				//printf("OPC_QINS_FAIL:%d, OPC_QINS_OK:%d, OPC_QINS_PK_ERROR:%d, OPC_QINS_SEL_ERROR:%d, Insertion Code:%d\n", 
				//		OPC_QINS_FAIL,    OPC_QINS_OK,    OPC_QINS_PK_ERROR,    OPC_QINS_SEL_ERROR, ins_code);
				/* insert the new packet at tail of subqueue 0 */
				//num_pkts = op_subq_stat (0, OPC_QSTAT_IN_PKSIZE);  // tamaño ocupado en el queue
					//printf(" pkts insert OK: %.0f\n", num_pkts);
				
				if (ins_code == OPC_QINS_FAIL)
					{
					/* if the insertion failed, discard the packet */
					num_pkts = op_subq_stat (0, OPC_QSTAT_IN_PKSIZE);  // tamaño ocupado en el queue
					printf("queued pkts: %.0f\n", num_pkts);
					
					ctr200=0;
					ctr201=0;
					pos_0=0;
					pos_1=0;
					
					for(n=0; n<num_pkts; n++)
						{
						q_pkt = op_subq_pk_access (0, n);
						op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);
						ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;
						
						if (ip_address == 200)
							{
							ctr200++;
							pos_0 = n;
							}
						else
							{
							if (ip_address == 201)
								{
								ctr201++;
								pos_1 = n;
								}
							}
						
						}
					
					//printf("queued pkts: %3.0f, type 200: %i, type 201: %i\n", num_pkts, ctr200, ctr201);
						
					if (ctr200 > ctr201)
						{
						q_pkt = op_subq_pk_remove (0, pos_0);
						op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);
						ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;
						op_pk_destroy (q_pkt);
						printf("ip_address %i\n", ip_address);
						pkt_destroy=1;
						
						}
					else
						{
						if (ctr201 > ctr200)
							{
							q_pkt = op_subq_pk_remove (0, pos_1);
							op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);
							ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;
							op_pk_destroy (q_pkt);
							printf("ip_address %i\n", ip_address);
							pkt_destroy2=1;
							}
						else
							{
							if (last_pkt_destroyed == 0)
								{
								q_pkt = op_subq_pk_remove (0, pos_1);
								op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);
								ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;
								op_pk_destroy (q_pkt);
								printf("ip_address %i\n", ip_address);
								
								if(ip_address==200){
								pkt_destroy=1;}
								if(ip_address==201){pkt_destroy2=1;}
								
								last_pkt_destroyed = 1;
								
								}
							else
								{
								q_pkt = op_subq_pk_remove (0, pos_0);
								op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);
								ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;
								op_pk_destroy (q_pkt);
								printf("ip_address %i\n", ip_address);
								
								if(ip_address==200){
								pkt_destroy=1;}
								if(ip_address==201){pkt_destroy2=1;}
								
								last_pkt_destroyed = 0;
								
								}
							}
						}
					
					ins_code = op_subq_pk_insert (0, pkt, OPC_QPOS_TAIL);
					if (ins_code != OPC_QINS_OK){ printf("Warning! Subqueue Insertion Failed!\n"); }
					//printf("OPC_QINS_FAIL:%i, OPC_QINS_OK:%i, Insertion Code:%i\n", OPC_QINS_FAIL, OPC_QINS_OK, ins_code);
					
				//	fr=fopen("C:\\opnet_temp\\leaky.txt","a+");
					/*
					fr=fopen("C:\\Users\\Liliana\\Dropbox\\Tesis\\Excel\\leaky.txt","a+");
				    fprintf(fr,"%i %f %u\n", ip_address, op_sim_time(), 0);
				    fclose(fr);*/
					
					if ((ip_address == 200)&&(time200 == 0))
						{
						printf("first 200 packet time: %f\n", op_sim_time());
					    time200++;
					    }
					else
						{
						if ((ip_address == 201)&&(time201 == 0))
							{
							printf("first 201 packet time: %f\n", op_sim_time());
							time201++;
							}
						}
						
					if(pkt_destroy==1){
					
					total_loss_ctr++;
					wait=0;
					if(loss_ctr<=1){
					wait=1;
					++ctr1;
					printf("<3<3<3<3ctr1 %d\n",ctr1);
					++loss;}
					if(loss_ctr>1&&wait==0){
					loss_avg_ctr++;
					loss_avg = (1.0-(double)(1.0/loss_avg_ctr))*loss_avg + (double)(1.0/loss_avg_ctr)*((double)loss/(double)loss_ctr);
					printf("loss average = %f, loss_ctr: %d, loss_avg_ctr: %d,  loss: %d\n", loss_avg, loss_ctr, loss_avg_ctr, loss);
					loss_ctr_ant=loss_ctr;
					loss_ctr = 0;
					loss=1;
					wait=0;
					g_loss=loss_avg;
					
					
					}
					}
					if(pkt_destroy2==1){
					
					
					wait2=0;
					
					if(loss_ctr2<=1){
					wait2=1;
					++ctr2;
					printf("<3<3<3<3 ctr2 %d\n",ctr2);
					++loss2;}
					if(loss_ctr2>1&&wait2==0){
					loss_avg_ctr2++;
					loss_avg2 = (1.0-(double)(1.0/loss_avg_ctr2))*loss_avg2 + (double)(1.0/loss_avg_ctr2)*((double)loss/(double)loss_ctr2);
					printf("loss average2 = %f, loss_ctr2: %d, loss_avg_ctr2: %d,  loss2: %d\n", loss_avg2, loss_ctr2, loss_avg_ctr2, loss2);
					loss_ctr_ant2=loss_ctr2;
					loss_ctr2 = 0;
					loss2=1;
					wait2=0;
					g_loss2=loss_avg2;
					
					}
					}
					
					
					}
					
				
				if (ins_code == OPC_QINS_OK)
					/* otherwise schedule arrived packet */
					{
					if (sched_ptr <= op_sim_time())
						{
						sched_ptr = op_sim_time() + pkt_proc_time;
						}
					else
						{
						sched_ptr += pkt_proc_time;
						}
						
					op_intrpt_schedule_self (sched_ptr, 0);
					
				//	fs=fopen("C:\\opnet_temp\\leaky_send.txt","a+");
					
					loss_ctr++;
					}
				
				
				
					
				}
				FSM_PROFILE_SECTION_OUT (state0_enter_exec)

			/** state (INS_TAIL) exit executives **/
			FSM_STATE_EXIT_FORCED (0, "INS_TAIL", "fifo_fair_owl_old [INS_TAIL exit execs]")


			/** state (INS_TAIL) transition processing **/
			FSM_TRANSIT_FORCE (2, state2_enter_exec, ;, "default", "", "INS_TAIL", "BRANCH", " ", "fifo_fair_owl_old [INS_TAIL -> BRANCH : default / ]")
				/*---------------------------------------------------------*/



			/** state (SEND_HEAD) enter executives **/
			FSM_STATE_ENTER_FORCED (1, "SEND_HEAD", state1_enter_exec, "fifo_fair_owl_old [SEND_HEAD enter execs]")
				FSM_PROFILE_SECTION_IN ("fifo_fair_owl_old [SEND_HEAD enter execs]", state1_enter_exec)
				{
				//printf("Entered SEND_HEAD State\n");
				//FILE *fs;
				/* a request has been made to access the queue */
				/* check if its empty */
				if (!op_subq_empty (0))
				    {
				    /* access the first packet in the subqueue */
				    pkt = op_subq_pk_remove (0, OPC_QPOS_HEAD);
				
					/* forward it to the destination */
					/* without causing a stream interrupt */
					op_pk_nfd_access (pkt, "fields", &pkt_fields_ptr);
					ip_address_send = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;
					
				    op_pk_send(pkt, 0);
					
					if(ip_address==200){loss_ctr++;}
					if(ip_address==201){loss_ctr2++;}
					/*
					fs=fopen("C:\\Users\\Liliana\\Dropbox\\Tesis\\Excel\\leaky_send.txt","a+");
				    fprintf(fs,"%i %f\n", ip_address_send, op_sim_time() );
				    fclose(fs);*/
				
				    }
				}
				FSM_PROFILE_SECTION_OUT (state1_enter_exec)

			/** state (SEND_HEAD) exit executives **/
			FSM_STATE_EXIT_FORCED (1, "SEND_HEAD", "fifo_fair_owl_old [SEND_HEAD exit execs]")


			/** state (SEND_HEAD) transition processing **/
			FSM_TRANSIT_FORCE (2, state2_enter_exec, ;, "default", "", "SEND_HEAD", "BRANCH", " ", "fifo_fair_owl_old [SEND_HEAD -> BRANCH : default / ]")
				/*---------------------------------------------------------*/



			/** state (BRANCH) enter executives **/
			FSM_STATE_ENTER_UNFORCED (2, "BRANCH", state2_enter_exec, "fifo_fair_owl_old [BRANCH enter execs]")
				FSM_PROFILE_SECTION_IN ("fifo_fair_owl_old [BRANCH enter execs]", state2_enter_exec)
				{
				//printf("Entered BRANCH State\n");
				}
				FSM_PROFILE_SECTION_OUT (state2_enter_exec)

			/** blocking after enter executives of unforced state. **/
			FSM_EXIT (5,"fifo_fair_owl_old")


			/** state (BRANCH) exit executives **/
			FSM_STATE_EXIT_UNFORCED (2, "BRANCH", "fifo_fair_owl_old [BRANCH exit execs]")


			/** state (BRANCH) transition processing **/
			FSM_PROFILE_SECTION_IN ("fifo_fair_owl_old [BRANCH trans conditions]", state2_trans_conds)
			FSM_INIT_COND (SERVICE)
			FSM_TEST_COND (ARRIVAL)
			FSM_TEST_LOGIC ("BRANCH")
			FSM_PROFILE_SECTION_OUT (state2_trans_conds)

			FSM_TRANSIT_SWITCH
				{
				FSM_CASE_TRANSIT (0, 1, state1_enter_exec, ;, "SERVICE", "", "BRANCH", "SEND_HEAD", " ", "fifo_fair_owl_old [BRANCH -> SEND_HEAD : SERVICE / ]")
				FSM_CASE_TRANSIT (1, 0, state0_enter_exec, ;, "ARRIVAL", "", "BRANCH", "INS_TAIL", " ", "fifo_fair_owl_old [BRANCH -> INS_TAIL : ARRIVAL / ]")
				}
				/*---------------------------------------------------------*/



			/** state (INIT) enter executives **/
			FSM_STATE_ENTER_FORCED_NOLABEL (3, "INIT", "fifo_fair_owl_old [INIT enter execs]")
				FSM_PROFILE_SECTION_IN ("fifo_fair_owl_old [INIT enter execs]", state3_enter_exec)
				{
				my_id_queue=op_id_self();
				
				
				if (OPC_COMPCODE_FAILURE==op_ima_obj_attr_get_dbl (my_id_queue, "bit_rate", &bit_rate)){
				printf("Failure\n");
				}
				printf("bit rate %f\n",bit_rate);
				
				sched_ptr = 0.0;
				packet_size_bits = 12056;
				pkt_proc_time = packet_size_bits/bit_rate;
				
				time200 = 0;
				time201 = 0;
				
				//printf("Exited INIT State\n");
				last_pkt_destroyed = 0;
				}
				FSM_PROFILE_SECTION_OUT (state3_enter_exec)

			/** state (INIT) exit executives **/
			FSM_STATE_EXIT_FORCED (3, "INIT", "fifo_fair_owl_old [INIT exit execs]")


			/** state (INIT) transition processing **/
			FSM_TRANSIT_FORCE (2, state2_enter_exec, ;, "default", "", "INIT", "BRANCH", "tr_4", "fifo_fair_owl_old [INIT -> BRANCH : default / ]")
				/*---------------------------------------------------------*/



			}


		FSM_EXIT (3,"fifo_fair_owl_old")
		}
	}




void
_op_fifo_fair_owl_old_diag (OP_SIM_CONTEXT_ARG_OPT)
	{
	/* No Diagnostic Block */
	}




void
_op_fifo_fair_owl_old_terminate (OP_SIM_CONTEXT_ARG_OPT)
	{

	FIN_MT (_op_fifo_fair_owl_old_terminate ())


	/* No Termination Block */

	Vos_Poolmem_Dealloc (op_sv_ptr);

	FOUT
	}


/* Undefine shortcuts to state variables to avoid */
/* syntax error in direct access to fields of */
/* local variable prs_ptr in _op_fifo_fair_owl_old_svar function. */
#undef my_id_queue
#undef bit_rate
#undef ip_address
#undef loss_ctr
#undef loss_avg
#undef loss_avg_ctr
#undef packet_size_bits
#undef number_of_packets
#undef total_loss_ctr
#undef pkt_fields_ptr
#undef sched_ptr
#undef pkt_proc_time
#undef time200
#undef time201
#undef num_pkts
#undef last_pkt_destroyed
#undef ip_address_send
#undef pkt_destroy
#undef loss
#undef loss_ctr_ant
#undef wait
#undef loss_ctr2
#undef loss_avg2
#undef loss_avg_ctr2
#undef pkt_destroy2
#undef wait2
#undef loss2
#undef loss_ctr_ant2

#undef FIN_PREAMBLE_DEC
#undef FIN_PREAMBLE_CODE

#define FIN_PREAMBLE_DEC
#define FIN_PREAMBLE_CODE

VosT_Obtype
_op_fifo_fair_owl_old_init (int * init_block_ptr)
	{
	VosT_Obtype obtype = OPC_NIL;
	FIN_MT (_op_fifo_fair_owl_old_init (init_block_ptr))

	obtype = Vos_Define_Object_Prstate ("proc state vars (fifo_fair_owl_old)",
		sizeof (fifo_fair_owl_old_state));
	*init_block_ptr = 6;

	FRET (obtype)
	}

VosT_Address
_op_fifo_fair_owl_old_alloc (VosT_Obtype obtype, int init_block)
	{
#if !defined (VOSD_NO_FIN)
	int _op_block_origin = 0;
#endif
	fifo_fair_owl_old_state * ptr;
	FIN_MT (_op_fifo_fair_owl_old_alloc (obtype))

	ptr = (fifo_fair_owl_old_state *)Vos_Alloc_Object (obtype);
	if (ptr != OPC_NIL)
		{
		ptr->_op_current_block = init_block;
#if defined (OPD_ALLOW_ODB)
		ptr->_op_current_state = "fifo_fair_owl_old [INIT enter execs]";
#endif
		}
	FRET ((VosT_Address)ptr)
	}



void
_op_fifo_fair_owl_old_svar (void * gen_ptr, const char * var_name, void ** var_p_ptr)
	{
	fifo_fair_owl_old_state		*prs_ptr;

	FIN_MT (_op_fifo_fair_owl_old_svar (gen_ptr, var_name, var_p_ptr))

	if (var_name == OPC_NIL)
		{
		*var_p_ptr = (void *)OPC_NIL;
		FOUT
		}
	prs_ptr = (fifo_fair_owl_old_state *)gen_ptr;

	if (strcmp ("my_id_queue" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->my_id_queue);
		FOUT
		}
	if (strcmp ("bit_rate" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->bit_rate);
		FOUT
		}
	if (strcmp ("ip_address" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->ip_address);
		FOUT
		}
	if (strcmp ("loss_ctr" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss_ctr);
		FOUT
		}
	if (strcmp ("loss_avg" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss_avg);
		FOUT
		}
	if (strcmp ("loss_avg_ctr" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss_avg_ctr);
		FOUT
		}
	if (strcmp ("packet_size_bits" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->packet_size_bits);
		FOUT
		}
	if (strcmp ("number_of_packets" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->number_of_packets);
		FOUT
		}
	if (strcmp ("total_loss_ctr" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->total_loss_ctr);
		FOUT
		}
	if (strcmp ("pkt_fields_ptr" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->pkt_fields_ptr);
		FOUT
		}
	if (strcmp ("sched_ptr" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->sched_ptr);
		FOUT
		}
	if (strcmp ("pkt_proc_time" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->pkt_proc_time);
		FOUT
		}
	if (strcmp ("time200" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->time200);
		FOUT
		}
	if (strcmp ("time201" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->time201);
		FOUT
		}
	if (strcmp ("num_pkts" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->num_pkts);
		FOUT
		}
	if (strcmp ("last_pkt_destroyed" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->last_pkt_destroyed);
		FOUT
		}
	if (strcmp ("ip_address_send" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->ip_address_send);
		FOUT
		}
	if (strcmp ("pkt_destroy" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->pkt_destroy);
		FOUT
		}
	if (strcmp ("loss" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss);
		FOUT
		}
	if (strcmp ("loss_ctr_ant" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss_ctr_ant);
		FOUT
		}
	if (strcmp ("wait" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->wait);
		FOUT
		}
	if (strcmp ("loss_ctr2" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss_ctr2);
		FOUT
		}
	if (strcmp ("loss_avg2" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss_avg2);
		FOUT
		}
	if (strcmp ("loss_avg_ctr2" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss_avg_ctr2);
		FOUT
		}
	if (strcmp ("pkt_destroy2" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->pkt_destroy2);
		FOUT
		}
	if (strcmp ("wait2" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->wait2);
		FOUT
		}
	if (strcmp ("loss2" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss2);
		FOUT
		}
	if (strcmp ("loss_ctr_ant2" , var_name) == 0)
		{
		*var_p_ptr = (void *) (&prs_ptr->loss_ctr_ant2);
		FOUT
		}
	*var_p_ptr = (void *)OPC_NIL;

	FOUT
	}

