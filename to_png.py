from PIL import Image
import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
def ppm_to_png(ppm_file, png_file):
    with open(ppm_file, 'rb') as file:
        # 跳过文件头，直到找到图像数据
        file.readline().decode('utf-8').rstrip()  # Read and discard the "P6" magic number
        width, height = map(int, file.readline().decode('utf-8').rstrip().split())
        max_val = int(file.readline().decode('utf-8').rstrip())
        assert max_val == 255, 'Max value should be 255 for P6 PPM files'
        
        # 读取图像数据
        image_data = file.read()
        
        # 将PPM数据转换为RGB格式
        image = Image.frombytes('RGB', (width, height), image_data, 'raw', 'RGB', 0, 1)
        
        # 保存为PNG格式
        image.save(png_file, 'PNG')
 
# 使用函数转换文件
for i in range(121):
    ppm_to_png('./data/'+str(i)+'.ppm','./data/'+str(i)+'.png')