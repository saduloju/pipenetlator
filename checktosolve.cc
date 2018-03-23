
void process_debug(array <int> &node_table, vector<Real> &lengths,
                   array <int> &node_table_check, vector<Real> &lengths_check,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &diameters_check, vector<Real> &hw_coeffs_check,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					vector<Real> &external_flows_check, vector<Real> &initial_heads_check, 
					vector <Real> &frictn_ress, const int max_pipes, const int max_nodes,
					vector <Real> &frictn_ress_check, const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes,int &reservoir_node, Real &reservoir_head,
    				int &num_pipes_check, int &num_nodes_check,int &reservoir_node_check, Real &reservoir_head_check,
					Real &maxr, string &title, bool &debug,   bool &runsolve)
 { 

 runsolve= false; 

//numpipes
 if ( !num_pipes = num_pipes_check)
    { num_pipes_check = num_pipes;
      runsolve=true;
	}
//num_nodes
 if ( !num_nodes = num_nodes_check)
    { num_nodes_check = num_nodes;
      runsolve=true;
	} 
 // reservoir_node
 if ( !reservoir_node = reservoir_node_check)
    { reservoir_node_check = reservoir_node;
      runsolve=true;
	} 
// reservoir_head
 if ( !reservoir_head = reservoir_head_check)
    { reservoir_head_check = reservoir_head;
      runsolve=true;
	} 

 
 //lengths
for(i=1; i<=num_pipes; i++)
 {if(! lengths(i) = lengths_check(i))
   {lengths_check(i) = lengths(i);cout<< "Thank God! this work\n|n";
    runsolve =true;
   }
 }
   
 //diameters
for(i=1; i<=num_pipes; i++)
 {if(! diameters(i) = diameters_check(i))
   {diameters_check(i) = diameters(i);cout<< "Thank God! this work\n|n";
    runsolve =true;
   }
 }
 
 //hw_coeffs
for(i=1; i<=num_pipes; i++)
 {if(! hw_coeffs(i) = hw_coeffs_check(i))
   {hw_coeffs_check(i) = hw_coeffs(i);cout<< "Thank God! this work\n|n";
    runsolve =true;
   }
 } 
 
  //frictn_ress
for(i=1; i<=num_pipes; i++)
 {if(! frictn_ress(i) = frictn_ress_check(i))
   {frictn_ress_check(i) = frictn_ress(i);cout<< "Thank God! this work\n|n";
    runsolve =true;
   }
 } 
 
 
 
 
 //external_flows
for(i=1; i<=num_nodes; i++)
 {if(! external_flows(i) = external_flows_check(i))
   {external_flows_check(i) = iexternal_flows(i);cout<< "Thank God! this work\n|n";
    runsolve =true;
//	return;
   }
 }
 
  //initial heads
for(i=1; i<=num_nodes; i++)
 {if(! initial_heads(i) = initial_heads_check(i))
   {initial_heads_check(i) = initial_heads(i);cout<< "Thank God! this work\n|n";
    runsolve =true;
//	return;
   }
 }
 
 for(i=1; i<=num_pipes; i++)
  {for(j=1; i<=2; j++)
	{if(node_table(i,j) = node_table_check(i,j))
	  {node_table_check(i,j)= node_table_check(i,j);
       runsolve =true;
      }
    }
  }  
		
   
return;
 }