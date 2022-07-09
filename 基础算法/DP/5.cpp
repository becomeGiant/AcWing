优化存在的问题
f[i,j]=max(f[i-1,j],f[i-1,j+v]+w,f[i-1,j+2v]+2w,...,f[i-1,j+sv]+sw)
f[i,j-v]=max(       f[i-1,j-v],  f[i-1,j-2v]+w,... ,f[i-1,j-sv]+(s-1)w,f[i-1,j-(s+1)v]+sw)  //需要多减去一个v
