
package as.andc.sys;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;
import android.graphics.*;


public class HelloJni extends Activity
{
 
	FrameBufferView mainview;
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

       
//        TextView  tv = new TextView(this);
//        tv.setText( stringFromJNI() );
		
		
		mainview=new FrameBufferView(this);
		mainview.init();
        setContentView(mainview);
		
		initJniId();
		native_drawString("hello");
    }

    
	
	
	public Canvas getCanvas()
	{
		return mainview.getCanvas();
	}
	
	
	public native void native_drawString(String s);
	public void draw(String s)
	{
		Paint p=new Paint();
		p.setColor(Color.WHITE);
		p.setTextSize(32);
		getCanvas().drawText(s,100,100,p);
	}
	
    public native String  stringFromJNI();

	public native void initJniId();
	static {
        System.loadLibrary("kernal");
    }
}
