from building import *
Import('rtconfig')

src   = []
cwd   = GetCurrentDir()

# add ft6206 src files.
if GetDepend('PKG_USING_CST816X'):
    src += Glob('src/cst816x.c')

if GetDepend('PKG_USING_CST816X_SAMPLE'):
    src += Glob('samples/cst816x_sample.c')

# add ft6206 include path.
path  = [cwd + '/inc']

# add src and include to group.
group = DefineGroup('cst816x', src, depend = ['PKG_USING_CST816X'], CPPPATH = path)

Return('group')
