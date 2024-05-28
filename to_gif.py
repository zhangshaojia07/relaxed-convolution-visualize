from PIL import Image
import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
# 我们先取其中一张图片
im = Image.open("./data/0.png")

images=[]
for i in range(1,121):
    images.append(Image.open("./data/"+str(i)+".png"))

# duration  gif持续时间  单位毫秒   我们设置为500毫秒(值越小，图片变化越快)
im.save("out.gif", save_all=True, append_images=images, loop=0, duration=150, comment="")
