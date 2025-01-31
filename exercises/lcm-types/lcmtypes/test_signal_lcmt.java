/* LCM type definition class file
 * This file was automatically generated by lcm-gen
 * DO NOT MODIFY BY HAND!!!!
 */

package lcmtypes;
 
import java.io.*;
import java.util.*;
import lcm.lcm.*;
 
public final class test_signal_lcmt implements lcm.lcm.LCMEncodable
{
    public float pos;
    public float rpy;
    public float q_knee;
    public float q_hip;
    public float timestep;
 
    public test_signal_lcmt()
    {
    }
 
    public static final long LCM_FINGERPRINT;
    public static final long LCM_FINGERPRINT_BASE = 0xf118f1fd346cc493L;
 
    static {
        LCM_FINGERPRINT = _hashRecursive(new ArrayList<Class<?>>());
    }
 
    public static long _hashRecursive(ArrayList<Class<?>> classes)
    {
        if (classes.contains(lcmtypes.test_signal_lcmt.class))
            return 0L;
 
        classes.add(lcmtypes.test_signal_lcmt.class);
        long hash = LCM_FINGERPRINT_BASE
            ;
        classes.remove(classes.size() - 1);
        return (hash<<1) + ((hash>>63)&1);
    }
 
    public void encode(DataOutput outs) throws IOException
    {
        outs.writeLong(LCM_FINGERPRINT);
        _encodeRecursive(outs);
    }
 
    public void _encodeRecursive(DataOutput outs) throws IOException
    {
        outs.writeFloat(this.pos); 
 
        outs.writeFloat(this.rpy); 
 
        outs.writeFloat(this.q_knee); 
 
        outs.writeFloat(this.q_hip); 
 
        outs.writeFloat(this.timestep); 
 
    }
 
    public test_signal_lcmt(byte[] data) throws IOException
    {
        this(new LCMDataInputStream(data));
    }
 
    public test_signal_lcmt(DataInput ins) throws IOException
    {
        if (ins.readLong() != LCM_FINGERPRINT)
            throw new IOException("LCM Decode error: bad fingerprint");
 
        _decodeRecursive(ins);
    }
 
    public static lcmtypes.test_signal_lcmt _decodeRecursiveFactory(DataInput ins) throws IOException
    {
        lcmtypes.test_signal_lcmt o = new lcmtypes.test_signal_lcmt();
        o._decodeRecursive(ins);
        return o;
    }
 
    public void _decodeRecursive(DataInput ins) throws IOException
    {
        this.pos = ins.readFloat();
 
        this.rpy = ins.readFloat();
 
        this.q_knee = ins.readFloat();
 
        this.q_hip = ins.readFloat();
 
        this.timestep = ins.readFloat();
 
    }
 
    public lcmtypes.test_signal_lcmt copy()
    {
        lcmtypes.test_signal_lcmt outobj = new lcmtypes.test_signal_lcmt();
        outobj.pos = this.pos;
 
        outobj.rpy = this.rpy;
 
        outobj.q_knee = this.q_knee;
 
        outobj.q_hip = this.q_hip;
 
        outobj.timestep = this.timestep;
 
        return outobj;
    }
 
}

