//Print puntos
    vector<punto>::iterator it;
    for (it = puntos.begin(); it != puntos.end(); ++it){
        printf("%d %d\n",it->x,it->y);
    }