/*
===========================================================================
Loom SDK
Copyright 2011, 2012, 2013 
The Game Engine Company, LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. 
===========================================================================
*/

package loom.platform
{
    /**
     * Specifier for the type of keyboard to show.
     * 
     * @see IMEDelegate.attachWithIME
     */
    public enum LoomKeyboardType
    {
        /**
         * Normal alphanumeric keyboard.
         */
        Default = 0,

        /**
         * Keyboard designed for email entry.
         */
        Email = 1,

        /**
         * Keyboard for URL entry.
         */
        URL = 2,

        /**
         * Phone dial pad.
         */
        Phone = 3,

        /**
         * Numerical keypad.
         */
        NumberPad = 4
    };
 
    /**
     * Helper to communicate with Loom's IME API.
     *
     * Accepting fully international text input is complex; this class
     * hooks into the platform APIs for text input to allow
     * bringing up on-screen input methods, and communicates via 
     * delegates any text that the user composes.
     *
     * Be aware that key down/up events may not have any relationship
     * to the text the user inputs; for instance, consider a German user
     * entering text on a German keyboard, or an East Asian user using a
     * tablet for input.
     *
     * Each text input area should have its own instance of this class.
     */
    //[Native(managed)]     
    public  class IMEDelegate
    {
        /**
         * Set this to false if you don't want to allow an IME method to be 
         * attached. True by default.
         */
        public var canAttachWithIME:Boolean;

        /**
         * Set this to false if you don't want to allow an IME method to be 
         * detached. True by default.
         */
        public var canDetachWithIME:Boolean;

        /**
         * Update this with your text field's content from time to time; it is
         * used if the input method needs to display the text.
         */
        public var contentText:String;

        /**
         * Called once we've attached an IME. No parameters.
         */
        public var onDidAttachWithIME:NativeDelegate;

        /**
         * Called once we've detached an IME. No parameters.
         */
        public var onDidDetachWithIME:NativeDelegate;

        /**
         * Called as text input becomes available. Is passed a String 
         * containing the new text, and an int with the length in bytes.
         */
        public var onInsertText:NativeDelegate; // String, int

        /**
         * Called when delete is fired; this indicates you should delete one
         * character to the left. No parameters.
         */
        public var onDeleteBackward:NativeDelegate;

        /**
         * Indicates the on-screen keyboard is becoming visible. No
         * parameters.
         */
        public var onKeyboardWillShow:NativeDelegate;
        
        /**
         * Indicates the on-screen keyboard has become visible. No
         * parameters. (iOS Only)
         */
        public var onKeyboardDidShow:NativeDelegate;

        /**
         * Indicates the on-screen keyboard is becoming invisible. No
         * parameters.
         */
        public var onKeyboardWillHide:NativeDelegate;

        /**
         * Indicates the on-screen keyboard has become invisible. No
         * parameters. (iOS Only)
         */
        public var onKeyboardDidHide:NativeDelegate;

        /**
         * Called to trigger the IME. Returns false if the IME was not
         * triggered.
         *
         * @param type The type of keyboard to show. @see LoomKeyboardType
         */
        public function attachWithIME(type:LoomKeyboardType=0):Boolean
        {
        return false;
        }

        /**
         * Called to remove the IME. Returns false if the IME was not
         * removed.
         */
        public function detachWithIME():Boolean
        {
        return false;
        }

    }
}