// automatically generated, do not modify

package mbtool.daemon.v3;

import java.nio.*;
import java.lang.*;
import java.util.*;
import com.google.flatbuffers.*;

@SuppressWarnings("unused")
public final class SignedExecResponse extends Table {
  public static SignedExecResponse getRootAsSignedExecResponse(ByteBuffer _bb) { return getRootAsSignedExecResponse(_bb, new SignedExecResponse()); }
  public static SignedExecResponse getRootAsSignedExecResponse(ByteBuffer _bb, SignedExecResponse obj) { _bb.order(ByteOrder.LITTLE_ENDIAN); return (obj.__init(_bb.getInt(_bb.position()) + _bb.position(), _bb)); }
  public SignedExecResponse __init(int _i, ByteBuffer _bb) { bb_pos = _i; bb = _bb; return this; }

  public short result() { int o = __offset(4); return o != 0 ? bb.getShort(o + bb_pos) : 0; }
  public String errorMsg() { int o = __offset(6); return o != 0 ? __string(o + bb_pos) : null; }
  public ByteBuffer errorMsgAsByteBuffer() { return __vector_as_bytebuffer(6, 1); }
  public int exitStatus() { int o = __offset(8); return o != 0 ? bb.getInt(o + bb_pos) : 0; }
  public int termSig() { int o = __offset(10); return o != 0 ? bb.getInt(o + bb_pos) : 0; }

  public static int createSignedExecResponse(FlatBufferBuilder builder,
      short result,
      int error_msgOffset,
      int exit_status,
      int term_sig) {
    builder.startObject(4);
    SignedExecResponse.addTermSig(builder, term_sig);
    SignedExecResponse.addExitStatus(builder, exit_status);
    SignedExecResponse.addErrorMsg(builder, error_msgOffset);
    SignedExecResponse.addResult(builder, result);
    return SignedExecResponse.endSignedExecResponse(builder);
  }

  public static void startSignedExecResponse(FlatBufferBuilder builder) { builder.startObject(4); }
  public static void addResult(FlatBufferBuilder builder, short result) { builder.addShort(0, result, 0); }
  public static void addErrorMsg(FlatBufferBuilder builder, int errorMsgOffset) { builder.addOffset(1, errorMsgOffset, 0); }
  public static void addExitStatus(FlatBufferBuilder builder, int exitStatus) { builder.addInt(2, exitStatus, 0); }
  public static void addTermSig(FlatBufferBuilder builder, int termSig) { builder.addInt(3, termSig, 0); }
  public static int endSignedExecResponse(FlatBufferBuilder builder) {
    int o = builder.endObject();
    return o;
  }
};

