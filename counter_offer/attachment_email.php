<?php
/**
 * @File a mime mail attachment class used for sending emails with attachments.
 *
 * Forked from https://github.com/ngmaloney/Attachment-Email
 * Modified from a version created at http://www.kavoir.com/2009/08/php-email-attachment-class.html
 **/
class AttachmentEmail {
	
  /*private*/ public $to = '';
  /*private*/ public $from = '';
  /*private*/ public $subject = '';
  /*private*/ public $message = '';
  /*private*/ public $attachments = '';

  /**
   * Function for defining email
   *
   * @param $to
   *   Email recipient address
   * @param $from
   *   Email sender address
   * @param $message
   *   Message text of body. (currenlty plain text only)
   * @param $attachment (optional)
   *   An indexed array of associative arrays.
   *   Each of the inner arrays represents a file attachment.
   *
   *   Example:
   *   array(
   *     'name' => 'attachment.pdf',
   *     'path' => '/tmp/attachment.pdf',
   *     'type' => 'image/gif',
   *   )
   **/
  public function __construct($to, $from, $subject, $message, $attachments = array()) {
    $this->to = $to;
    $this->from = $from;
    $this->subject = $subject;
    $this->message = $message;
    $this->attachments = $attachments;
    $this->boundary = md5(date('r', time()));
  }

  /**
   * Hook for sending actual email
   **/
  public function send() {
    $header = "From: ".($this->from)." <".($this->from).">" . PHP_EOL;
    $header .= "Reply-To: ".($this->from). PHP_EOL;

    if (!empty($this->attachments)) {

      $header .= "Content-Transfer-Encoding: 7bit" . PHP_EOL;
      $header .= "Content-Type: multipart/mixed; boundary=\"". $this->boundary . '"' . PHP_EOL;
      $header .= "MIME-Version: 1.0" . PHP_EOL;

      $message = "This is a multi-part message in MIME format." . PHP_EOL . PHP_EOL;
      $message .= "--". $this->boundary . PHP_EOL;
      $message .= "Content-Transfer-Encoding: binary" . PHP_EOL;
      $message .= "Content-type:text/plain; charset=iso-8859-1" . PHP_EOL . PHP_EOL;
      $message .= $this->message . PHP_EOL;
      $message .= $this->get_binary_attachments() . PHP_EOL;
      $message .= '--'. $this->boundary .'--' . PHP_EOL;
      $this->message = $message;
    }

    if (mail($this->to, $this->subject, $this->message, $header)) {
      return true;
    }
    else {
      return false;
    }
  }

  public function get_binary_attachments() {
    $output = '';
    foreach($this->attachments as $attachment) {

      $attachment_bin = file_get_contents($attachment['path']);
      $attachment_bin = chunk_split(base64_encode($attachment_bin));

      $output .= '--'. $this->boundary . PHP_EOL;
      $output .= 'Content-Type: '. $attachment['type'] .'; name="'. basename($attachment['path']) .'"' . PHP_EOL;
      $output .= 'Content-Transfer-Encoding: base64' . PHP_EOL;
      $output .= 'Content-Disposition: attachment' . PHP_EOL . PHP_EOL;
      $output .= $attachment_bin . PHP_EOL . PHP_EOL;
    }
    return $output;
  }
}