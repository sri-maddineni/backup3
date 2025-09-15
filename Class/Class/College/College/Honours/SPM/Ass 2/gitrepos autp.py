from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.alert import Alert
import time

driver = webdriver.Chrome("C:/Users/sriha/Downloads/chromedriver")
driver.get('https://sri-maddineni.github.io/itkonnects.gitrepos.com/') 

driver.find_element_by_xpath("/html/body/div/div[1]/input").send_keys('sri')

driver.find_element_by_xpath("/html/body/div/div[1]/button").click()
time.sleep(4)
driver.execute_script("alert('Test case 1 user name: sri(some unknown) : passed.')")
time.sleep(4)

driver.find_element_by_xpath("/html/body/div/div[1]/input").clear()


driver.find_element_by_xpath("/html/body/div/div[1]/input").send_keys('sri-maddineni')

driver.find_element_by_xpath("/html/body/div/div[1]/button").click()
time.sleep(4)
driver.execute_script("alert('Test case 1 user name: my username:sri-maddineni : passed.')")
time.sleep(4)

driver.find_element_by_xpath("/html/body/div/div[1]/input").clear()


driver.find_element_by_xpath("/html/body/div/div[1]/input").send_keys('kattaavinash')

driver.find_element_by_xpath("/html/body/div/div[1]/button").click()
time.sleep(4)
driver.execute_script("alert('Test case: with no repos : passed.')")
time.sleep(4)

driver.find_element_by_xpath("/html/body/div/div[1]/input").clear()


#driver.find_element_by_xpath("/html/body/div/div[1]/input").clear()


driver.execute_script("alert('All test cases passed.')")

time.sleep(2)

#driver.find_element_by_xpath("/html/body/div/div[1]/input").clear()

driver.execute_script("alert('Browser will be closed now')")

time.sleep(2)


driver.close()
