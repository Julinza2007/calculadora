void prod_vectorial(int* vector1, int* vector2, int n){
    if (n == 3){
        int vector_x;
        int vector_y;
        int vector_z;
        vector_x = (vector1[2] * vector2[3]) - (vector1[3] * vector2 [2]); 
        vector_y = (vector1[1] * vector2[3]) - (vector1[3] * vector2 [1]); 
        vector_z = (vector1[1] * vector2[2]) - (vector1[2] * vector2 [1]); 
        
        printf ("el producto vectorial da X=%d - Y=%d - Z=%d", vector_x, vector_z, vector_y);
    }
    else{
        printf ("No se puede llevar a cabo el producto vectorial ya que la longitud del vector no es de 3");
    }
}

}

