// Now we collect all edges that cross the cut: 
  for(auto &i : scomp){
      for(auto &j : tcomp){
          if(maxf.isEdge(i,j))
            cout << i << " " << j << endl;
      }
  }