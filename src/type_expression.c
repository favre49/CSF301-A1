/*
 * Definition of a Type Expression
 *
 * Authors:
 * Rahul Ganesh Prabhu (2018A7PS0193P)
 * Shreyas Kera (2018A7PS1119P)
 * Achyut Anand Tadepalli (2018A7PS1118P)
 * Raghurama Varma Gonela (2018A7PS1120P)
 */

#include "type_expression.h"

int isTEEqual(TypeExpression a, TypeExpression b)
{
  if (a.t != b.t)
    return 0;

  if (a.t==TYPE_RECTANGULAR_ARRAY)
  {
    RectArray ar = a.array.r;
    RectArray br = b.array.r;

    // This check should always be true but might as well
    if(ar.basic_element_type != br.basic_element_type)
      return 0;
    if (ar.dimension_count != br.dimension_count)
      return 0;
    for (size_t i = 0; i < ar.dimension_count; i++)
    {
      if (ar.highs[i] != br.highs[i] || ar.lows[i] != br.lows[i])
        return 0;
    }
  }

  if(a.t == TYPE_JAGGED_ARRAY)
  {
    // TODO: jagged array equality
    JaggedArray aj = a.array.j;
    JaggedArray bj = b.array.j;
    if (aj.dimension_count != bj.dimension_count)
      return 0;
    if(aj.range_R1[0]!=bj.range_R1[0] || aj.range_R1[1]!=bj.range_R1[1])
      return 0;
    if(aj.dimension_count==2)
    {
      for(int i=0; i<aj.range_R1[1]-aj.range_R1[0]+1; i++)
      {
        if(aj.range_R2[i].length!=bj.range_R2[i].length)
          return 0;
      }
    }
    else
    {
      for(int i=0; i<aj.range_R1[1]-aj.range_R1[0]+1; i++)
      {
        if(aj.range_R2[i].length!=bj.range_R2[i].length)
          return 0;
        for(int j=0;j<aj.range_R2[i].length;j++)
        {
          if(aj.range_R2[i].ranges[j]!=bj.range_R2[i].ranges[j])
            return 0;
        }
      }
    }

  }

  return 1;
}

// Print the type expression
void printTE(TypeExpression a)
{
  char out[300] = "";
  char buffer[300]  = "";
  strcat(out,"<type= ");
  sprintf(buffer,"%s",type_map[a.t]);
  strcat(out,buffer);
  if (a.t==TYPE_RECTANGULAR_ARRAY)
  {
    sprintf(buffer,", dimensions=%d",a.array.r.dimension_count);
    strcat(out,buffer);
    for (int dim = 1; dim <= a.array.r.dimension_count; dim++)
    {
      sprintf(buffer," range_R%d=(%d,%d)", dim, a.array.r.lows[dim-1], a.array.r.highs[dim-1]);
      strcat(out,buffer);
    }
    strcat(out," basicElementType = integer");
  }
  if (a.t==TYPE_JAGGED_ARRAY)
  {
    JaggedArray j=a.array.j;
    sprintf(buffer,", dimensions=%d, ", j.dimension_count);
    strcat(out,buffer);
    sprintf(buffer,"range_R1=(%d,%d), ", j.range_R1[0], j.range_R1[1]);
    strcat(out,buffer);
    int count=j.range_R1[1] - j.range_R1[0] + 1;
    printf("range_R2=(");
    if(j.dimension_count==2)
    {
      for(int dim = 0; dim < count-1; dim++)
      {
        sprintf(buffer,"%d,", j.range_R2[dim].length);
        strcat(out,buffer);
      }
      sprintf(buffer,"%d),", j.range_R2[count-1].length);
      strcat(out,buffer);
    }
    else
    {
      for(int dim = 0; dim < count-1; dim++)
      {
        sprintf(buffer,"%d[", j.range_R2[dim].length);
        strcat(out,buffer);
        for(int dim2=0; dim2 < j.range_R2[dim].length-1; dim2++)
        {
          sprintf(buffer,"%d,", j.range_R2[dim].ranges[dim2]);
          strcat(out,buffer);
        }
        sprintf(buffer,"%d], ", j.range_R2[dim].ranges[j.range_R2[dim].length-1]);
        strcat(out,buffer);
      }
      sprintf(buffer,"%d[", j.range_R2[count-1].length);
      strcat(out,buffer);
      for(int dim2=0; dim2 < j.range_R2[count-1].length-1; dim2++)
      {
        sprintf(buffer,"%d,", j.range_R2[count-1].ranges[dim2]);
        strcat(out,buffer);
      }
      sprintf(buffer,"%d]),", j.range_R2[count-1].ranges[j.range_R2[count-1].length-1]);
      strcat(out,buffer);
    }
    strcat(out," basicElementType = integer");
  }
  strcat(out,">");
  printf("%-50s",out);
}
