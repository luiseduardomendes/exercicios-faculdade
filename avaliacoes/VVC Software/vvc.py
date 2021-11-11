import os
import sys
import re

VideoList = ['RaceHorsesC']

nameCfg = ['low_delay_', 'random_access', 'all_intra']
QPList = ['22', '27', '32', '37']

NFrames = sys.argv[1]

cfgList = ['encoder_lowdelay_vtm.cfg', 'encoder_randomaccess_vtm.cfg', 'encoder_intra_vtm.cfg']

for video in VideoList:
    for config in cfgList:
        for qp in QPList:
            fd1 = open('config_' + config + 'result_' + video + 'QP_' + qp + '.txt', 'w')

            os.system(
                './EncoderAppStatic -c ../cfg/' + config + ' -c ../cfg/per-sequence/' + video + '.cfg --QP=' + qp + ' -f ' + NFrames + ' >> ' + 'EncoderAppStatic' + 'report_' + video + '_' + qp + '.txt')
            # perguntar para o professor
            fd = open('config_' + config + 'result_' + video + 'QP_' + qp + '.txt', 'r')
            l = fd.readline()

            while 'SUMMARY' not in l:
                l = fd.readline()

            l = fd.readline()
            l = fd.readline()

            infos = re.match(r'\s*\d*\s*a\s*(\d*.\d*)\s*(\d*.\d*).*', l, 0)

            fd1.write(qp + ',' + infos.group(1) + ',' + infos.group(2) + '\n')

        fd.close()
        fd1.close()
    
for video in VideoList:
    fd1 = open('correct/result_' + video + '.txt', 'w')
    for config in cfgList:
        for qp in QPList:
            os.system(
                './EncoderAppStatic -c ' + cfg + ' -i ' + video + ' --QP=' + qp + ' -f ' + NFrames + ' >> correct/report_' + video + '_' + qp + '.txt')
            fd = open('correct/report_' + video + '_' + qp + '.txt', 'r')
            l = fd.readline()
            while 'SUMMARY' not in l:
                l = fd.readline()
            l = fd.readline()
            l = fd.readline()
            infos = re.match(r'\s*\d*\s*a\s*(\d*.\d*)\s*(\d*.\d*).*', l, 0)
            fd1.write(qp + ',' + infos.group(1) + ',' + infos.group(2) + '\n')
    fd.close()
    fd1.close()

for video in VideoList:
    fd1 = open('nohad/result_' + video + '_without_SATD.txt', 'w')
    for config in cfgList:
        for qp in QPList:
            os.system(
                './EncoderAppStatic -c ' + cfg + ' -i' + video + ' --QP=' + qp + ' -f ' + NFrames + ' --HadamardME=0 >> nohad/report_' + video + '_' + qp + '.txt')
            fd = open('nohad/report_' + video + '_' + qp + '.txt', 'r')
            l = fd.readline()
            while 'SUMMARY' not in l:
                l = fd.readline()
            l = fd.readline()
            l = fd.readline()
            infos = re.match(r'\s*\d*\s*a\s*(\d*.\d*)\s*(\d*.\d*).*', l, 0)
            fd1.write(qp + ',' + infos.group(1) + ',' + infos.group(2) + '\n')
    fd.close()
    fd1.close()
