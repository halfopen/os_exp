/*
        模拟页面地址重定位
*/
import java.util.Scanner;
import java.util.Random;

public class Page{
        public int A;//逻辑地址
        public int L;//页面大小
        public int P;//页面号
        public int W;//页内位移
        public int pageNum;
        public int pageList[];//页表
        public int size;
        public int Address; //逻辑地址
        
        Page(){
                this.size = 128;
                
        }
        public void setL(int L){
                this.L = L;
                //初始化一个页表
                pageNum=128/L+1;
                int temp;
                int sum=0;
	        //cout<< "num=" << Page_num<< endl;
	        pageList = new int[pageNum];
	        pageList[0]=1;
	        Random random = new Random();
	        for(int i=0;i<pageNum;i++)
	        {
		        temp=random.nextInt(128)%(3) + 1;
		        sum+=temp;
		        pageList[i]+=sum;
	        }
	        if(sum >size){
	                System.out.println("空间不足，分配失败");
	        }
        }
        // 地址转换
        public Boolean translate(int A){
               
                System.out.println("逻辑地址:"+A);
	        W = A % L;
	        P = A / L;
	        System.out.println("页号:"+P+" 偏移量:"+W);
	        Address = pageList[P]*L+W;
	        System.out.println("物理地址为:"+Address);
                return true;
        }
        
        public void showPageList(){
                System.out.println(" 页号 : 块号 ");
	        for(int i=0;i<pageNum;i++)
	        {
		        System.out.printf(" %3d : %3d\n",i,pageList[i]);
	        }
        }
        
        /* 主函数*/
        public static void main(String[] args){
                Scanner scn = new Scanner(System.in);
                
                Page page = new Page();
                int l,a;
                System.out.println("请输入页面大小:");
                l = scn.nextInt();
                while(l>0){
                        System.out.println("请输入逻辑地址");
                        a = scn.nextInt();
                        page.setL(l);
                        page.showPageList();
                        page.translate(a);
                        System.out.println("请输入页面大小:");
                        l = scn.nextInt();
                }
                
        }
}
