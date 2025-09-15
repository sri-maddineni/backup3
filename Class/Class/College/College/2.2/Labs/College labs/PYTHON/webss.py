
from selenium import webdriver
import time

from selenium.webdriver.common.keys import Keys

reg="y18ace"

''' to change dept 
1.change reg format
2.loop variable  and then its done
3.create folder
4.change path of saving'''

noi=401
time.sleep(0.5)


browser = webdriver.Chrome()
browser.get("http://becbapatla.ac.in:8080/STUDENTINFO/index_r20.html")
hbox = browser.find_element_by_xpath("/html/body/div/div[1]/div[5]/div/div/form/center/font/input[1]")
hbox.send_keys("y20ait507")
submit = browser.find_element_by_xpath("/html/body/div/div[1]/div[5]/div/div/form/center/font/input[2]")
submit.click()
#browser.find_element_by_xpath("/html/body/div/div/div[5]/div/div/div/table[1]/tbody/tr[1]/td[2]/img").screenshot("C:\\Users\sriha\Desktop\programs\python\sel\y20acs\y20acs("+str(i)+").png")
browser.get_screenshot_as_file(filename="file.pdf")
browser.quit()


#for i in range(noi,593,1):
  #  try:
        
   # except:
   #     pass





#













'''try:
    
except:
    pass

#actions = ActionChains(browser)

#actions.context_click(img).perform()

'''

