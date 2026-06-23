bool judgeCircle(char* moves) {
  int x =0;
  int y =0;
  for(int i =0; moves[i]!='\0';i++){
    if(moves[i]=='U')
    {
        y+=1;
    }
    else if(moves[i]=='D'){
        y-=1;
    }
    if(moves[i]=='R')
    {
        x+=1;
    }
    else if(moves[i]=='L'){
        x-=1;
    }
  }
  return(x==0&&y==0);  
}