MIL_3_Tfile_Hdr_ 145A 140A modeler 9 55AD451D 55BCF3D4 4 OWL-1 Liliana 0 0 none none 0 0 none BD7CD663 2D73 0 0 0 0 0 0 1e80 8                                                                                                                                                                                                                                                                                                                                                                                                  ??g?      @   ?   ?  ?  ?  ?  'Q  'U  'Y  ']  'w  +k  +o  ?      bit_rate   ???????   ????               ????              ????              ????           ?Z                 	   begsim intrpt         
   ????   
   doc file            	nd_module      endsim intrpt             ????      failure intrpts            disabled      intrpt interval         ԲI?%??}????      priority              ????      recovery intrpts            disabled      subqueue         
            count    ???   
   ????   
      list   	???   
          
   
   super priority             ????          8   Objid	\my_id_queue;       double	\bit_rate;       int	\ip_address;       int	\loss_ctr;       double	\loss_avg;       int	\loss_avg_ctr;       int	\packet_size_bits;       int	\number_of_packets;       int	\total_loss_ctr;       "IpT_Dgram_Fields*	\pkt_fields_ptr;       double	\sched_ptr;       double	\pkt_proc_time;       int	\time200;       int	\time201;       double	\num_pkts;       int	\last_pkt_destroyed;       int	\ip_address_send;       int	\pkt_destroy;       
int	\loss;       int	\loss_ctr_ant;       
int	\wait;       int	\loss_ctr2;       double	\loss_avg2;       int	\loss_avg_ctr2;       int	\pkt_destroy2;       int	\wait2;       int	\loss2;       int	\loss_ctr_ant2;          Packet          *pkt;   Packet			*q_pkt;   	int				n;   int				ctr200;   int				ctr201;   int				pos_0;   int				pos_1;   int				ins_code;      #include "ip_addr_v4.h"   #include "ip_dgram_sup.h"       #define CLEAN_ADDR 3232235776       8#define ARRIVAL     op_intrpt_type () == OPC_INTRPT_STRM   8#define SERVICE     op_intrpt_type () == OPC_INTRPT_SELF   5//#define CLOSE (op_intrpt_type()==OPC_INTRPT_ENDSIM)   int ctr1=0;   int ctr2=0;       double  g_loss=0;   double  g_loss2=0;   wait=0;   loss_ctr_ant=0;                                               ?  J          
   INS_TAIL   
       
   ?   //FILE *fr;       pkt_destroy=0;   pkt_destroy2=0;   %//printf("Entered INS_TAIL State\n");       */* a new packet has arrived; acquire it */   $pkt = op_pk_get (op_intrpt_strm ());   4//op_pk_nfd_access (pkt, "fields", &pkt_fields_ptr);   H//ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;       5ins_code = op_subq_pk_insert (0, pkt, OPC_QPOS_TAIL);   o//printf("OPC_QINS_FAIL:%d, OPC_QINS_OK:%d, OPC_QINS_PK_ERROR:%d, OPC_QINS_SEL_ERROR:%d, Insertion Code:%d\n",    Z//		OPC_QINS_FAIL,    OPC_QINS_OK,    OPC_QINS_PK_ERROR,    OPC_QINS_SEL_ERROR, ins_code);   1/* insert the new packet at tail of subqueue 0 */   R//num_pkts = op_subq_stat (0, OPC_QSTAT_IN_PKSIZE);  // tama?o ocupado en el queue   /	//printf(" pkts insert OK: %.0f\n", num_pkts);       if (ins_code == OPC_QINS_FAIL)   	{   2	/* if the insertion failed, discard the packet */   Q	num_pkts = op_subq_stat (0, OPC_QSTAT_IN_PKSIZE);  // tama?o ocupado en el queue   )	printf("queued pkts: %.0f\n", num_pkts);   	   
	ctr200=0;   
	ctr201=0;   		pos_0=0;   		pos_1=0;   	   	for(n=0; n<num_pkts; n++)   		{   #		q_pkt = op_subq_pk_access (0, n);   6		op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);   H		ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;   		   		if (ip_address == 200)   			{   			ctr200++;   			pos_0 = n;   			}   		else   			{   			if (ip_address == 201)   				{   				ctr201++;   				pos_1 = n;   				}   			}   		   		}   	   X	//printf("queued pkts: %3.0f, type 200: %i, type 201: %i\n", num_pkts, ctr200, ctr201);   		   	if (ctr200 > ctr201)   		{   '		q_pkt = op_subq_pk_remove (0, pos_0);   6		op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);   H		ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;   		op_pk_destroy (q_pkt);   (		printf("ip_address %i\n", ip_address);   		pkt_destroy=1;   		   		}   	else   		{   		if (ctr201 > ctr200)   			{   (			q_pkt = op_subq_pk_remove (0, pos_1);   7			op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);   I			ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;   			op_pk_destroy (q_pkt);   )			printf("ip_address %i\n", ip_address);   			pkt_destroy2=1;   			}   		else   			{   			if (last_pkt_destroyed == 0)   				{   )				q_pkt = op_subq_pk_remove (0, pos_1);   8				op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);   J				ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;   				op_pk_destroy (q_pkt);   *				printf("ip_address %i\n", ip_address);   				   				if(ip_address==200){   				pkt_destroy=1;}   (				if(ip_address==201){pkt_destroy2=1;}   				   				last_pkt_destroyed = 1;   				   				}   			else   				{   )				q_pkt = op_subq_pk_remove (0, pos_0);   8				op_pk_nfd_access (q_pkt, "fields", &pkt_fields_ptr);   J				ip_address = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;   				op_pk_destroy (q_pkt);   *				printf("ip_address %i\n", ip_address);   				   				if(ip_address==200){   				pkt_destroy=1;}   (				if(ip_address==201){pkt_destroy2=1;}   				   				last_pkt_destroyed = 0;   				   				}   			}   		}   	   6	ins_code = op_subq_pk_insert (0, pkt, OPC_QPOS_TAIL);   Q	if (ins_code != OPC_QINS_OK){ printf("Warning! Subqueue Insertion Failed!\n"); }   i	//printf("OPC_QINS_FAIL:%i, OPC_QINS_OK:%i, Insertion Code:%i\n", OPC_QINS_FAIL, OPC_QINS_OK, ins_code);   	   .//	fr=fopen("C:\\opnet_temp\\leaky.txt","a+");   	/*   G	fr=fopen("C:\\Users\\Liliana\\Dropbox\\Tesis\\Excel\\leaky.txt","a+");   ;    fprintf(fr,"%i %f %u\n", ip_address, op_sim_time(), 0);       fclose(fr);*/   	   )	if ((ip_address == 200)&&(time200 == 0))   		{   7		printf("first 200 packet time: %f\n", op_sim_time());   	    time200++;   	    }   	else   		{   *		if ((ip_address == 201)&&(time201 == 0))   			{   8			printf("first 201 packet time: %f\n", op_sim_time());   			time201++;   			}   		}   		   	if(pkt_destroy==1){   	   	total_loss_ctr++;   	wait=0;   	if(loss_ctr<=1){   	wait=1;   	++ctr1;   "	printf("<3<3<3<3ctr1 %d\n",ctr1);   		++loss;}   	if(loss_ctr>1&&wait==0){   	loss_avg_ctr++;   s	loss_avg = (1.0-(double)(1.0/loss_avg_ctr))*loss_avg + (double)(1.0/loss_avg_ctr)*((double)loss/(double)loss_ctr);   r	printf("loss average = %f, loss_ctr: %d, loss_avg_ctr: %d,  loss: %d\n", loss_avg, loss_ctr, loss_avg_ctr, loss);   	loss_ctr_ant=loss_ctr;   	loss_ctr = 0;   	loss=1;   	wait=0;   	g_loss=loss_avg;   	   	   	}   	}   	if(pkt_destroy2==1){   	   	   		wait2=0;   	   	if(loss_ctr2<=1){   		wait2=1;   	++ctr2;   #	printf("<3<3<3<3 ctr2 %d\n",ctr2);   
	++loss2;}   	if(loss_ctr2>1&&wait2==0){   	loss_avg_ctr2++;   x	loss_avg2 = (1.0-(double)(1.0/loss_avg_ctr2))*loss_avg2 + (double)(1.0/loss_avg_ctr2)*((double)loss/(double)loss_ctr2);   z	printf("loss average2 = %f, loss_ctr2: %d, loss_avg_ctr2: %d,  loss2: %d\n", loss_avg2, loss_ctr2, loss_avg_ctr2, loss2);   	loss_ctr_ant2=loss_ctr2;   	loss_ctr2 = 0;   		loss2=1;   		wait2=0;   	g_loss2=loss_avg2;   	   	}   	}   	   	   	}   	       if (ins_code == OPC_QINS_OK)   (	/* otherwise schedule arrived packet */   	{    	if (sched_ptr <= op_sim_time())   		{   ,		sched_ptr = op_sim_time() + pkt_proc_time;   		}   	else   		{   		sched_ptr += pkt_proc_time;   		}   		   (	op_intrpt_schedule_self (sched_ptr, 0);   	   3//	fs=fopen("C:\\opnet_temp\\leaky_send.txt","a+");   	   	loss_ctr++;   	}               	   
                     
   ????   
          pr_state      	   ?   Z          
   	SEND_HEAD   
       
      &//printf("Entered SEND_HEAD State\n");   //FILE *fs;   1/* a request has been made to access the queue */   /* check if its empty */   if (!op_subq_empty (0))       {   1    /* access the first packet in the subqueue */   /    pkt = op_subq_pk_remove (0, OPC_QPOS_HEAD);       $	/* forward it to the destination */   )	/* without causing a stream interrupt */   3	op_pk_nfd_access (pkt, "fields", &pkt_fields_ptr);   L	ip_address_send = pkt_fields_ptr->dest_addr.address.ipv4_addr - CLEAN_ADDR;   	       op_pk_send(pkt, 0);   	   !	if(ip_address==200){loss_ctr++;}   "	if(ip_address==201){loss_ctr2++;}   	/*   L	fs=fopen("C:\\Users\\Liliana\\Dropbox\\Tesis\\Excel\\leaky_send.txt","a+");   ;    fprintf(fs,"%i %f\n", ip_address_send, op_sim_time() );       fclose(fs);*/           }   
                     
   ????   
          pr_state         ?   ?          
   BRANCH   
       
      #//printf("Entered BRANCH State\n");   
                     
    ????   
          pr_state         Z   ?          
   INIT   
       J      my_id_queue=op_id_self();           Xif (OPC_COMPCODE_FAILURE==op_ima_obj_attr_get_dbl (my_id_queue, "bit_rate", &bit_rate)){   printf("Failure\n");   }   !printf("bit rate %f\n",bit_rate);       sched_ptr = 0.0;   packet_size_bits = 12056;   *pkt_proc_time = packet_size_bits/bit_rate;       time200 = 0;   time201 = 0;        //printf("Exited INIT State\n");   last_pkt_destroyed = 0;   J                     
   ????   
          pr_state                      ?  (      ?  9   ?     ?   ?          
       
       ????          ????          
   0????   
          ????                       pr_transition         	      ?   ?      ?   k   ?   ?   ?   ?          
       
       ????          ????          
   0????   
          ????                       pr_transition            	   ?   ?      ?   ?   ?   w          
       
       
   SERVICE   
       ????          
   0????   
          ????                       pr_transition               ?  	      ?   ?   ?  ,          
       
       
   ARRIVAL   
       ????          
   0????   
          ????                       pr_transition               ?   ?      m   ?   ?   ?          
   tr_4   
       ????          ????          
    ????   
          ????                       pr_transition                           
link_delay           +   General Process Description:   ----------------------------        ?The pc_fifo queueing process model accepts packets from any number of sources and holds them until it receives a request from another module to forward the next packet in the queue. The packets are forwarded in a first-in-first-out (FIFO) manner.        ?Note that the request to forward the packets should come in the form of an "access interrupt" delivered by the module which is the destination module for the concerned packets.               ICI Interfaces:   ---------------        None                Packet Formats:   ---------------        None                Statistic Wires:   ----------------        None                Process Registry:   -----------------        Not Applicable               Restrictions:   -------------        F1. The pc_fifo process model must be contained within a queue module.        c2. The source stream index of the output packet stream of the surrounding queue module should be 0.        