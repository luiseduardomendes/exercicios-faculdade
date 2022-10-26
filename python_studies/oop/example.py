video = 'BasketballDrive'
qps = ('22', '27', '32', '37')
precises = [f'{video}_QP{qp}.txt' for qp in qps]
satd = '4x4-1-RdCost4x4-1-8x8-1.cpp'
cfg = 'intra'
files = [f'log_{video}_qp{qp}_intra_{satd}_exec.gplog' for qp in qps]

frames = 32
n_qps = len(qps)

bdr = BD_Rate(VVC_output(files, qps, frames), VVC_output(precises, qps, frames), satd, video, cfg, n_qps)
bdr.to_excel('dt.xlsx')
