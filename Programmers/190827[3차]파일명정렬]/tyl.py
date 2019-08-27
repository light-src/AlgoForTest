# kakao_sorting_file_name
import re


def solution(files):
    order = []
    ph = re.compile('([\D]*)')
    pn = re.compile('([0-9]+)')
    for f in files:
        
        head = ph.match(f)
        num = pn.search(f)        
        
        for i,element in enumerate(order):
            if order:
                e1 = ph.match(element)
                e2 = pn.search(element)
                
                if head.group().lower() == e1.group().lower(): 
                    if int(num.group()) < int(e2.group()): order.insert(i,f) ; break
                elif head.group().lower() < e1.group().lower(): order.insert(i,f) ; break
        else: order.append(f)
        
    return order
        
    
if __name__ == "__main__":
    files = ['img12.png', 'img10.png', 'img02.png', 'img1.png', 'IMG01.GIF', 'img2.JPG']
    # files = ['F-5 Freedom Fighter', 'B-50 Superfortress', 'A-10 Thunderbolt II', 'F-14 Tomcat']
    # files = ['F-15']
    print(solution(files))
