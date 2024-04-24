int check(int id, int *id_array, int Elements) //works
{
  for (int i = 0; i < Elements; i++) 
  {
    if (*(id_array+i) == id) 
    {
      return 1;
    }
  }
  return 0;
}

const int limit = 512;
int Pitems = 0;
int Titems = 0;
int Sitems = 0;