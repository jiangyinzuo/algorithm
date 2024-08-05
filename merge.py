import os
import argparse


def merge_md(dir: str, output: str):
    with open(output, 'w', encoding='UTF-8') as tar_md:
        for f in os.walk(dir):
            if f[0].endswith('tools') or f[0].endswith('topic'):
                continue
            for file_name in f[2]:
                if file_name.endswith('.md'):
                    with open(f'{f[0]}/{file_name}', encoding='UTF-8') as md:
                        tar_md.writelines(md.readlines())


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', type=str, help='input a directory')
    parser.add_argument('-o', type=str, help='input a directory')
    args = parser.parse_args()
    merge_md(args.d, args.o)
