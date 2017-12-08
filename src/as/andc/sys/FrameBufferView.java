package as.andc.sys;
import android.view.*;
import android.view.SurfaceHolder.Callback;
import android.graphics.*;
import android.content.*;
import android.widget.*;

public class FrameBufferView extends SurfaceView implements Callback
{

	
	private boolean fbCanvasReady = false;
    private SurfaceHolder fbHolder = null;
    private Bitmap fbBitmap = null;
	
	private Context context;
	
	public Canvas can;
	public FrameBufferView(Context context)
	{
		super(context);
		fbHolder=this.getHolder();
		fbHolder.addCallback(this);
		this.context=context;
	}
	
	
	public void init()
	{
		fbCanvasReady=true;
		fbBitmap=Bitmap.createBitmap(720,1080,Bitmap.Config.ARGB_8888);
	    can=new Canvas(fbBitmap);
		can.drawColor(Color.DKGRAY);
		
		
	}
	
	
	public Canvas getCanvas()
	{
		return can;
	}
	
	@Override
	public void surfaceChanged(SurfaceHolder p1, int p2, int p3, int p4)
	{
		// TODO: Implement this method
	}

	@Override
	public void surfaceCreated(SurfaceHolder p1)
	{
		repaintView();
	}

	@Override
	public void surfaceDestroyed(SurfaceHolder p1)
	{
		// TODO: Implement this method
	}


	public void repaintView() {
        
            synchronized (fbBitmap) {
				
				
                if (fbHolder.getSurface().isValid()) {
                    Canvas lockCanvas = fbHolder.lockCanvas();
                    if (lockCanvas != null) {
						
						
                        lockCanvas.drawBitmap(fbBitmap, 0, 0, null);
                       /*
                        FrameBufferActivity.getInstance();)
                        if (FrameBufferActivity.enableSIP) {
                            lockCanvas.drawBitmap(fbKeyboard, (float) ((getWidth() - fbKeyboard.getWidth()) / VCENTER), (float) (getHeight() - fbKeyboard.getHeight()), null);
                        }
						*/
                        fbHolder.unlockCanvasAndPost(lockCanvas);
						
						
                    }
                }
            }
        }
    
	
}
