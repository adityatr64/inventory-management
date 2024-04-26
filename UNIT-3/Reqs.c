int check(int id, ids *id_path, int Elements) 
{
  for (int i = 0; i < Elements; i++) 
  {
    if ((id_path+i)->id == id) 
    {
      return 1;
    }
  }
  return 0;
}