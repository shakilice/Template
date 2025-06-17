// make sure the length of low and high are must be same
string low,high;
ll dp[20][4];
ll call(ll i,ll h){
  if(i>=low.size())return 0;
  if(dp[i][h]!=-1)return dp[i][h];
  ll ans=0;
  if(h==0){
    // Guess the initial valu

    for(ll j=0;j<=9;j++){
      if(j<low[i]-'0')continue;
      if(j>high[i]-'0')continue;
     // calculate_valu

      if(low[i]==high[i]&&j==low[i]-'0'){
        //v=call(i+1,0)+calculate_valu

        //update the Guess valu with compare the valu of v
        
      }
      else if(j>low[i]-'0'&&j<high[i]-'0'){
         //v=call(i+1,1)+calculate_valu

         //update the Guess valu with compare the valu of v
         
      }
      else if(j==low[i]-'0'){
         //v=call(i+1,2)+calculate_valu

         //update the Guess valu with compare the valu of v
        
      }
      else {
         //v=call(i+1,3)+calculate_valu

         //update the Guess valu with compare the valu of v
        
      }
    }
    // set answer=Guess valu

  }
  else if(h==1){
    // Guess the initial valu

    for(ll j=0;j<=9;j++){
       // calculate_valu

       //v=call(i+1,1)+calculate_valu

       //update the Guess valu with compare the valu of v

    }
    // set answer=Guess valu

  }
  else if(h==2){
    // Guess the initial valu

    for(ll j=0;j<=9;j++){
      if(j<low[i]-'0')continue;
       // calculate_valu

      else if(j==low[i]-'0'){
         //v=call(i+1,2)+calculate_valu

         //update the Guess valu with compare the valu of v
        
      }
      else if(j>low[i]-'0'){
         //v=call(i+1,1)+calculate_valu

         //update the Guess valu with compare the valu of v

      }
    }
    // set answer=Guess valu
     
  }
  else{
    // Guess the initial valu

    for(ll j=0;j<=9;j++){
      if(j>high[i]-'0')continue;
          // calculate_valu

      if(j==high[i]-'0'){
         //v=call(i+1,3)+calculate_valu

         //update the Guess valu with compare the valu of v
           
      }
      else if(j<high[i]-'0'){
         //v=call(i+1,1)+calculate_valu

         //update the Guess valu with compare the valu of v
          
      }
    }
    // set answer=Guess valu

  }
 return dp[i][h]=ans;
}
