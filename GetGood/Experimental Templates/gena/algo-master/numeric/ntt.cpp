# i n c l u d e < b i t s / s t d c + + . h >  
 u s i n g   n a m e s p a c e   s t d ;  
  
 t e m p l a t e   < t y p e n a m e   T >  
 T   i n v e r s e ( T   a ,   T   m )   {  
         T   u   =   0 ,   v   =   1 ;  
         w h i l e   ( a   ! =   0 )   {  
                 T   t   =   m   /   a ;  
                 m   - =   t   *   a ;   s w a p ( a ,   m ) ;  
                 u   - =   t   *   v ;   s w a p ( u ,   v ) ;  
         }  
         a s s e r t ( m   = =   1 ) ;  
         r e t u r n   u ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 c l a s s   M o d u l a r   {  
 p u b l i c :  
         u s i n g   T y p e   =   t y p e n a m e   d e c a y < d e c l t y p e ( T : : v a l u e ) > : : t y p e ;  
  
         c o n s t e x p r   M o d u l a r ( )   :   v a l u e ( )   { }  
         t e m p l a t e   < t y p e n a m e   U >  
         M o d u l a r ( c o n s t   U &   x )   {  
                 v a l u e   =   n o r m a l i z e ( x ) ;  
         }  
  
         t e m p l a t e   < t y p e n a m e   U >  
         s t a t i c   T y p e   n o r m a l i z e ( c o n s t   U &   x )   {  
                 T y p e   v ;  
                 i f   ( - m o d ( )   < =   x   & &   x   <   m o d ( ) )   v   =   s t a t i c _ c a s t < T y p e > ( x ) ;  
                 e l s e   v   =   s t a t i c _ c a s t < T y p e > ( x   %   m o d ( ) ) ;  
                 i f   ( v   <   0 )   v   + =   m o d ( ) ;  
                 r e t u r n   v ;  
         }  
  
         c o n s t   T y p e &   o p e r a t o r ( ) ( )   c o n s t   {   r e t u r n   v a l u e ;   }  
         t e m p l a t e   < t y p e n a m e   U >  
         e x p l i c i t   o p e r a t o r   U ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < U > ( v a l u e ) ;   }  
         c o n s t e x p r   s t a t i c   T y p e   m o d ( )   {   r e t u r n   T : : v a l u e ;   }  
  
         M o d u l a r &   o p e r a t o r + = ( c o n s t   M o d u l a r &   o t h e r )   {   i f   ( ( v a l u e   + =   o t h e r . v a l u e )   > =   m o d ( ) )   v a l u e   - =   m o d ( ) ;   r e t u r n   * t h i s ;   }  
         M o d u l a r &   o p e r a t o r - = ( c o n s t   M o d u l a r &   o t h e r )   {   i f   ( ( v a l u e   - =   o t h e r . v a l u e )   <   0 )   v a l u e   + =   m o d ( ) ;   r e t u r n   * t h i s ;   }  
         t e m p l a t e   < t y p e n a m e   U >   M o d u l a r &   o p e r a t o r + = ( c o n s t   U &   o t h e r )   {   r e t u r n   * t h i s   + =   M o d u l a r ( o t h e r ) ;   }  
         t e m p l a t e   < t y p e n a m e   U >   M o d u l a r &   o p e r a t o r - = ( c o n s t   U &   o t h e r )   {   r e t u r n   * t h i s   - =   M o d u l a r ( o t h e r ) ;   }  
         M o d u l a r &   o p e r a t o r + + ( )   {   r e t u r n   * t h i s   + =   1 ;   }  
         M o d u l a r &   o p e r a t o r - - ( )   {   r e t u r n   * t h i s   - =   1 ;   }  
         M o d u l a r   o p e r a t o r + + ( i n t )   {   M o d u l a r   r e s u l t ( * t h i s ) ;   * t h i s   + =   1 ;   r e t u r n   r e s u l t ;   }  
         M o d u l a r   o p e r a t o r - - ( i n t )   {   M o d u l a r   r e s u l t ( * t h i s ) ;   * t h i s   - =   1 ;   r e t u r n   r e s u l t ;   }  
         M o d u l a r   o p e r a t o r - ( )   c o n s t   {   r e t u r n   M o d u l a r ( - v a l u e ) ;   }  
  
         t e m p l a t e   < t y p e n a m e   U   =   T >  
         t y p e n a m e   e n a b l e _ i f < i s _ s a m e < t y p e n a m e   M o d u l a r < U > : : T y p e ,   i n t > : : v a l u e ,   M o d u l a r > : : t y p e &   o p e r a t o r * = ( c o n s t   M o d u l a r &   r h s )   {  
 # i f d e f   _ W I N 3 2  
                 u i n t 6 4 _ t   x   =   s t a t i c _ c a s t < i n t 6 4 _ t > ( v a l u e )   *   s t a t i c _ c a s t < i n t 6 4 _ t > ( r h s . v a l u e ) ;  
                 u i n t 3 2 _ t   x h   =   s t a t i c _ c a s t < u i n t 3 2 _ t > ( x   > >   3 2 ) ,   x l   =   s t a t i c _ c a s t < u i n t 3 2 _ t > ( x ) ,   d ,   m ;  
                 a s m (  
                     " d i v l   % 4 ;   \ n \ t "  
                     :   " = a "   ( d ) ,   " = d "   ( m )  
                     :   " d "   ( x h ) ,   " a "   ( x l ) ,   " r "   ( m o d ( ) )  
                 ) ;  
                 v a l u e   =   m ;  
 # e l s e  
                 v a l u e   =   n o r m a l i z e ( s t a t i c _ c a s t < i n t 6 4 _ t > ( v a l u e )   *   s t a t i c _ c a s t < i n t 6 4 _ t > ( r h s . v a l u e ) ) ;  
 # e n d i f  
                 r e t u r n   * t h i s ;  
         }  
  
         t e m p l a t e   < t y p e n a m e   U   =   T >  
         t y p e n a m e   e n a b l e _ i f < i s _ s a m e < t y p e n a m e   M o d u l a r < U > : : T y p e ,   i n t 6 4 _ t > : : v a l u e ,   M o d u l a r > : : t y p e &   o p e r a t o r * = ( c o n s t   M o d u l a r &   r h s )   {  
                 i n t 6 4 _ t   q   =   s t a t i c _ c a s t < i n t 6 4 _ t > ( s t a t i c _ c a s t < l o n g   d o u b l e > ( v a l u e )   *   r h s . v a l u e   /   m o d ( ) ) ;  
                 v a l u e   =   n o r m a l i z e ( v a l u e   *   r h s . v a l u e   -   q   *   m o d ( ) ) ;  
                 r e t u r n   * t h i s ;  
         }  
  
         t e m p l a t e   < t y p e n a m e   U   =   T >  
         t y p e n a m e   e n a b l e _ i f < ! i s _ i n t e g r a l < t y p e n a m e   M o d u l a r < U > : : T y p e > : : v a l u e ,   M o d u l a r > : : t y p e &   o p e r a t o r * = ( c o n s t   M o d u l a r &   r h s )   {  
                 v a l u e   =   n o r m a l i z e ( v a l u e   *   r h s . v a l u e ) ;  
                 r e t u r n   * t h i s ;  
         }  
  
         M o d u l a r &   o p e r a t o r / = ( c o n s t   M o d u l a r &   o t h e r )   {   r e t u r n   * t h i s   * =   M o d u l a r ( i n v e r s e ( o t h e r . v a l u e ,   m o d ( ) ) ) ;   }  
  
         t e m p l a t e   < t y p e n a m e   U >  
         f r i e n d   c o n s t   M o d u l a r < U > &   a b s ( c o n s t   M o d u l a r < U > &   v )   {   r e t u r n   v ;   }  
  
         t e m p l a t e   < t y p e n a m e   U >  
         f r i e n d   b o o l   o p e r a t o r = = ( c o n s t   M o d u l a r < U > &   l h s ,   c o n s t   M o d u l a r < U > &   r h s ) ;  
  
         t e m p l a t e   < t y p e n a m e   U >  
         f r i e n d   b o o l   o p e r a t o r < ( c o n s t   M o d u l a r < U > &   l h s ,   c o n s t   M o d u l a r < U > &   r h s ) ;  
  
         t e m p l a t e   < t y p e n a m e   U >  
         f r i e n d   s t d : : i s t r e a m &   o p e r a t o r > > ( s t d : : i s t r e a m &   s t r e a m ,   M o d u l a r < U > &   n u m b e r ) ;  
  
 p r i v a t e :  
         T y p e   v a l u e ;  
 } ;  
  
 t e m p l a t e   < t y p e n a m e   T >   b o o l   o p e r a t o r = = ( c o n s t   M o d u l a r < T > &   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   l h s . v a l u e   = =   r h s . v a l u e ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   b o o l   o p e r a t o r = = ( c o n s t   M o d u l a r < T > &   l h s ,   U   r h s )   {   r e t u r n   l h s   = =   M o d u l a r < T > ( r h s ) ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   b o o l   o p e r a t o r = = ( U   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   = =   r h s ;   }  
  
 t e m p l a t e   < t y p e n a m e   T >   b o o l   o p e r a t o r ! = ( c o n s t   M o d u l a r < T > &   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   ! ( l h s   = =   r h s ) ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   b o o l   o p e r a t o r ! = ( c o n s t   M o d u l a r < T > &   l h s ,   U   r h s )   {   r e t u r n   ! ( l h s   = =   r h s ) ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   b o o l   o p e r a t o r ! = ( U   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   ! ( l h s   = =   r h s ) ;   }  
  
 t e m p l a t e   < t y p e n a m e   T >   b o o l   o p e r a t o r < ( c o n s t   M o d u l a r < T > &   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   l h s . v a l u e   <   r h s . v a l u e ;   }  
  
 t e m p l a t e   < t y p e n a m e   T >   M o d u l a r < T >   o p e r a t o r + ( c o n s t   M o d u l a r < T > &   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   + =   r h s ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   M o d u l a r < T >   o p e r a t o r + ( c o n s t   M o d u l a r < T > &   l h s ,   U   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   + =   r h s ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   M o d u l a r < T >   o p e r a t o r + ( U   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   + =   r h s ;   }  
  
 t e m p l a t e   < t y p e n a m e   T >   M o d u l a r < T >   o p e r a t o r - ( c o n s t   M o d u l a r < T > &   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   - =   r h s ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   M o d u l a r < T >   o p e r a t o r - ( c o n s t   M o d u l a r < T > &   l h s ,   U   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   - =   r h s ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   M o d u l a r < T >   o p e r a t o r - ( U   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   - =   r h s ;   }  
  
 t e m p l a t e   < t y p e n a m e   T >   M o d u l a r < T >   o p e r a t o r * ( c o n s t   M o d u l a r < T > &   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   * =   r h s ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   M o d u l a r < T >   o p e r a t o r * ( c o n s t   M o d u l a r < T > &   l h s ,   U   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   * =   r h s ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   M o d u l a r < T >   o p e r a t o r * ( U   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   * =   r h s ;   }  
  
 t e m p l a t e   < t y p e n a m e   T >   M o d u l a r < T >   o p e r a t o r / ( c o n s t   M o d u l a r < T > &   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   / =   r h s ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   M o d u l a r < T >   o p e r a t o r / ( c o n s t   M o d u l a r < T > &   l h s ,   U   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   / =   r h s ;   }  
 t e m p l a t e   < t y p e n a m e   T ,   t y p e n a m e   U >   M o d u l a r < T >   o p e r a t o r / ( U   l h s ,   c o n s t   M o d u l a r < T > &   r h s )   {   r e t u r n   M o d u l a r < T > ( l h s )   / =   r h s ;   }  
  
 t e m p l a t e < t y p e n a m e   T ,   t y p e n a m e   U >  
 M o d u l a r < T >   p o w e r ( c o n s t   M o d u l a r < T > &   a ,   c o n s t   U &   b )   {  
         a s s e r t ( b   > =   0 ) ;  
         M o d u l a r < T >   x   =   a ,   r e s   =   1 ;  
         U   p   =   b ;  
         w h i l e   ( p   >   0 )   {  
                 i f   ( p   &   1 )   r e s   * =   x ;  
                 x   * =   x ;  
                 p   > > =   1 ;  
         }  
         r e t u r n   r e s ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 b o o l   I s Z e r o ( c o n s t   M o d u l a r < T > &   n u m b e r )   {  
         r e t u r n   n u m b e r ( )   = =   0 ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 s t r i n g   t o _ s t r i n g ( c o n s t   M o d u l a r < T > &   n u m b e r )   {  
         r e t u r n   t o _ s t r i n g ( n u m b e r ( ) ) ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 s t d : : o s t r e a m &   o p e r a t o r < < ( s t d : : o s t r e a m &   s t r e a m ,   c o n s t   M o d u l a r < T > &   n u m b e r )   {  
         r e t u r n   s t r e a m   < <   n u m b e r ( ) ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 s t d : : i s t r e a m &   o p e r a t o r > > ( s t d : : i s t r e a m &   s t r e a m ,   M o d u l a r < T > &   n u m b e r )   {  
         t y p e n a m e   c o m m o n _ t y p e < t y p e n a m e   M o d u l a r < T > : : T y p e ,   i n t 6 4 _ t > : : t y p e   x ;  
         s t r e a m   > >   x ;  
         n u m b e r . v a l u e   =   M o d u l a r < T > : : n o r m a l i z e ( x ) ;  
         r e t u r n   s t r e a m ;  
 }  
  
 / *  
 u s i n g   M o d T y p e   =   i n t ;  
  
 s t r u c t   V a r M o d   {   s t a t i c   M o d T y p e   v a l u e ;   } ;  
 M o d T y p e   V a r M o d : : v a l u e ;  
 M o d T y p e &   m d   =   V a r M o d : : v a l u e ;  
 u s i n g   M i n t   =   M o d u l a r < V a r M o d > ;  
 * /  
  
 c o n s t e x p r   i n t   m d   =   9 9 8 2 4 4 3 5 3 ;  
 u s i n g   M i n t   =   M o d u l a r < s t d : : i n t e g r a l _ c o n s t a n t < d e c a y < d e c l t y p e ( m d ) > : : t y p e ,   m d > > ;  
  
 v e c t o r < M i n t >   f a c t ( 1 ,   1 ) ;  
 v e c t o r < M i n t >   i n v _ f a c t ( 1 ,   1 ) ;  
  
 M i n t   C ( i n t   n ,   i n t   k )   {  
         i f   ( k   <   0   | |   k   >   n )   {  
                 r e t u r n   0 ;  
         }  
         w h i l e   ( ( i n t )   f a c t . s i z e ( )   <   n   +   1 )   {  
                 f a c t . p u s h _ b a c k ( f a c t . b a c k ( )   *   ( i n t )   f a c t . s i z e ( ) ) ;  
                 i n v _ f a c t . p u s h _ b a c k ( 1   /   f a c t . b a c k ( ) ) ;  
         }  
         r e t u r n   f a c t [ n ]   *   i n v _ f a c t [ k ]   *   i n v _ f a c t [ n   -   k ] ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 c l a s s   N T T   {  
   p u b l i c :  
     u s i n g   T y p e   =   t y p e n a m e   d e c a y < d e c l t y p e ( T : : v a l u e ) > : : t y p e ;  
  
     s t a t i c   T y p e   m d ;  
     s t a t i c   M o d u l a r < T >   r o o t ;  
     s t a t i c   i n t   b a s e ;  
     s t a t i c   i n t   m a x _ b a s e ;  
     s t a t i c   v e c t o r < M o d u l a r < T > >   r o o t s ;  
     s t a t i c   v e c t o r < i n t >   r e v ;  
  
     s t a t i c   v o i d   c l e a r ( )   {  
         r o o t   =   0 ;  
         b a s e   =   0 ;  
         m a x _ b a s e   =   0 ;  
         r o o t s . c l e a r ( ) ;  
         r e v . c l e a r ( ) ;  
     }  
  
     s t a t i c   v o i d   i n i t ( )   {  
         m d   =   T : : v a l u e ;  
         a s s e r t ( m d   > =   3   & &   m d   %   2   = =   1 ) ;  
         a u t o   t m p   =   m d   -   1 ;  
         m a x _ b a s e   =   0 ;  
         w h i l e   ( t m p   %   2   = =   0 )   {  
             t m p   / =   2 ;  
             m a x _ b a s e + + ;  
         }  
         r o o t   =   2 ;  
         w h i l e   ( p o w e r ( r o o t ,   ( m d   -   1 )   > >   1 )   = =   1 )   {  
             r o o t + + ;  
         }  
         a s s e r t ( p o w e r ( r o o t ,   m d   -   1 )   = =   1 ) ;  
         r o o t   =   p o w e r ( r o o t ,   ( m d   -   1 )   > >   m a x _ b a s e ) ;  
         b a s e   =   1 ;  
         r e v   =   { 0 ,   1 } ;  
         r o o t s   =   { 0 ,   1 } ;  
     }  
  
     s t a t i c   v o i d   e n s u r e _ b a s e ( i n t   n b a s e )   {  
         i f   ( m d   ! =   T : : v a l u e )   {  
             c l e a r ( ) ;  
         }  
         i f   ( r o o t s . e m p t y ( ) )   {  
             i n i t ( ) ;  
         }  
         i f   ( n b a s e   < =   b a s e )   {  
             r e t u r n ;  
         }  
         a s s e r t ( n b a s e   < =   m a x _ b a s e ) ;  
         r e v . r e s i z e ( 1   < <   n b a s e ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   ( 1   < <   n b a s e ) ;   i + + )   {  
             r e v [ i ]   =   ( r e v [ i   > >   1 ]   > >   1 )   +   ( ( i   &   1 )   < <   ( n b a s e   -   1 ) ) ;  
         }  
         r o o t s . r e s i z e ( 1   < <   n b a s e ) ;  
         w h i l e   ( b a s e   <   n b a s e )   {  
             M o d u l a r < T >   z   =   p o w e r ( r o o t ,   1   < <   ( m a x _ b a s e   -   1   -   b a s e ) ) ;  
             f o r   ( i n t   i   =   1   < <   ( b a s e   -   1 ) ;   i   <   ( 1   < <   b a s e ) ;   i + + )   {  
                 r o o t s [ i   < <   1 ]   =   r o o t s [ i ] ;  
                 r o o t s [ ( i   < <   1 )   +   1 ]   =   r o o t s [ i ]   *   z ;  
             }  
             b a s e + + ;  
         }  
     }  
  
     s t a t i c   v o i d   f f t ( v e c t o r < M o d u l a r < T > >   & a )   {  
         i n t   n   =   ( i n t )   a . s i z e ( ) ;  
         a s s e r t ( ( n   &   ( n   -   1 ) )   = =   0 ) ;  
         i n t   z e r o s   =   _ _ b u i l t i n _ c t z ( n ) ;  
         e n s u r e _ b a s e ( z e r o s ) ;  
         i n t   s h i f t   =   b a s e   -   z e r o s ;  
         f o r   ( i n t   i   =   0 ;   i   <   n ;   i + + )   {  
             i f   ( i   <   ( r e v [ i ]   > >   s h i f t ) )   {  
                 s w a p ( a [ i ] ,   a [ r e v [ i ]   > >   s h i f t ] ) ;  
             }  
         }  
         f o r   ( i n t   k   =   1 ;   k   <   n ;   k   < < =   1 )   {  
             f o r   ( i n t   i   =   0 ;   i   <   n ;   i   + =   2   *   k )   {  
                 f o r   ( i n t   j   =   0 ;   j   <   k ;   j + + )   {  
                     M o d u l a r < T >   x   =   a [ i   +   j ] ;  
                     M o d u l a r < T >   y   =   a [ i   +   j   +   k ]   *   r o o t s [ j   +   k ] ;  
                     a [ i   +   j ]   =   x   +   y ;  
                     a [ i   +   j   +   k ]   =   x   -   y ;  
                 }  
             }  
         }  
     }  
  
     s t a t i c   v e c t o r < M o d u l a r < T > >   m u l t i p l y ( v e c t o r < M o d u l a r < T > >   a ,   v e c t o r < M o d u l a r < T > >   b )   {  
         i f   ( a . e m p t y ( )   | |   b . e m p t y ( ) )   {  
             r e t u r n   { } ;  
         }  
         i n t   e q   =   ( a   = =   b ) ;  
         i n t   n e e d   =   ( i n t )   a . s i z e ( )   +   ( i n t )   b . s i z e ( )   -   1 ;  
         i n t   n b a s e   =   0 ;  
         w h i l e   ( ( 1   < <   n b a s e )   <   n e e d )   n b a s e + + ;  
         e n s u r e _ b a s e ( n b a s e ) ;  
         i n t   s z   =   1   < <   n b a s e ;  
         a . r e s i z e ( s z ) ;  
         b . r e s i z e ( s z ) ;  
         f f t ( a ) ;  
         i f   ( e q )   b   =   a ;   e l s e   f f t ( b ) ;  
         M o d u l a r < T >   i n v _ s z   =   1   /   s t a t i c _ c a s t < M o d u l a r < T > > ( s z ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   s z ;   i + + )   {  
             a [ i ]   * =   b [ i ]   *   i n v _ s z ;  
         }  
         r e v e r s e ( a . b e g i n ( )   +   1 ,   a . e n d ( ) ) ;  
         f f t ( a ) ;  
         a . r e s i z e ( n e e d ) ;  
         r e t u r n   a ;  
     }  
 } ;  
  
 t e m p l a t e   < t y p e n a m e   T >   t y p e n a m e   N T T < T > : : T y p e   N T T < T > : : m d ;  
 t e m p l a t e   < t y p e n a m e   T >   M o d u l a r < T >   N T T < T > : : r o o t ;  
 t e m p l a t e   < t y p e n a m e   T >   i n t   N T T < T > : : b a s e ;  
 t e m p l a t e   < t y p e n a m e   T >   i n t   N T T < T > : : m a x _ b a s e ;  
 t e m p l a t e   < t y p e n a m e   T >   v e c t o r < M o d u l a r < T > >   N T T < T > : : r o o t s ;  
 t e m p l a t e   < t y p e n a m e   T >   v e c t o r < i n t >   N T T < T > : : r e v ;  
  
 t e m p l a t e   < t y p e n a m e   T >  
 v e c t o r < M o d u l a r < T > >   i n v e r s e ( c o n s t   v e c t o r < M o d u l a r < T > > &   a )   {  
     a s s e r t ( ! a . e m p t y ( ) ) ;  
     i n t   n   =   ( i n t )   a . s i z e ( ) ;  
     v e c t o r < M o d u l a r < T > >   b   =   { 1   /   a [ 0 ] } ;  
     w h i l e   ( ( i n t )   b . s i z e ( )   <   n )   {  
         v e c t o r < M o d u l a r < T > >   x ( a . b e g i n ( ) ,   a . b e g i n ( )   +   m i n ( a . s i z e ( ) ,   b . s i z e ( )   < <   1 ) ) ;  
         x . r e s i z e ( b . s i z e ( )   < <   1 ) ;  
         b . r e s i z e ( b . s i z e ( )   < <   1 ) ;  
         v e c t o r < M o d u l a r < T > >   c   =   b ;  
         N T T < T > : : f f t ( c ) ;  
         N T T < T > : : f f t ( x ) ;  
         M o d u l a r < T >   i n v   =   1   /   s t a t i c _ c a s t < M o d u l a r < T > > ( ( i n t )   x . s i z e ( ) ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   ( i n t )   x . s i z e ( ) ;   i + + )   {  
             x [ i ]   * =   c [ i ]   *   i n v ;  
         }  
         r e v e r s e ( x . b e g i n ( )   +   1 ,   x . e n d ( ) ) ;  
         N T T < T > : : f f t ( x ) ;  
         r o t a t e ( x . b e g i n ( ) ,   x . b e g i n ( )   +   ( x . s i z e ( )   > >   1 ) ,   x . e n d ( ) ) ;  
         f i l l ( x . b e g i n ( )   +   ( x . s i z e ( )   > >   1 ) ,   x . e n d ( ) ,   0 ) ;  
         N T T < T > : : f f t ( x ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   ( i n t )   x . s i z e ( ) ;   i + + )   {  
             x [ i ]   * =   c [ i ]   *   i n v ;  
         }  
         r e v e r s e ( x . b e g i n ( )   +   1 ,   x . e n d ( ) ) ;  
         N T T < T > : : f f t ( x ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   ( ( i n t )   x . s i z e ( )   > >   1 ) ;   i + + )   {  
             b [ i   +   ( ( i n t )   x . s i z e ( )   > >   1 ) ]   =   - x [ i ] ;  
         }  
     }  
     b . r e s i z e ( n ) ;  
     r e t u r n   b ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 v e c t o r < M o d u l a r < T > >   i n v e r s e _ o l d ( v e c t o r < M o d u l a r < T > >   a )   {  
     a s s e r t ( ! a . e m p t y ( ) ) ;  
     i n t   n   =   ( i n t )   a . s i z e ( ) ;  
     i f   ( n   = =   1 )   {  
         r e t u r n   { 1   /   a [ 0 ] } ;  
     }  
     i n t   m   =   ( n   +   1 )   > >   1 ;  
     v e c t o r < M o d u l a r < T > >   b   =   i n v e r s e ( v e c t o r < M o d u l a r < T > > ( a . b e g i n ( ) ,   a . b e g i n ( )   +   m ) ) ;  
     i n t   n e e d   =   n   < <   1 ;  
     i n t   n b a s e   =   0 ;  
     w h i l e   ( ( 1   < <   n b a s e )   <   n e e d )   {  
         + + n b a s e ;  
     }  
     N T T < T > : : e n s u r e _ b a s e ( n b a s e ) ;  
     i n t   s i z e   =   1   < <   n b a s e ;  
     a . r e s i z e ( s i z e ) ;  
     b . r e s i z e ( s i z e ) ;  
     N T T < T > : : f f t ( a ) ;  
     N T T < T > : : f f t ( b ) ;  
     M o d u l a r < T >   i n v   =   1   /   s t a t i c _ c a s t < M o d u l a r < T > > ( s i z e ) ;  
     f o r   ( i n t   i   =   0 ;   i   <   s i z e ;   + + i )   {  
         a [ i ]   =   ( 2   -   a [ i ]   *   b [ i ] )   *   b [ i ]   *   i n v ;  
     }  
     r e v e r s e ( a . b e g i n ( )   +   1 ,   a . e n d ( ) ) ;  
     N T T < T > : : f f t ( a ) ;  
     a . r e s i z e ( n ) ;  
     r e t u r n   a ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 v e c t o r < M o d u l a r < T > >   o p e r a t o r * ( c o n s t   v e c t o r < M o d u l a r < T > > &   a ,   c o n s t   v e c t o r < M o d u l a r < T > > &   b )   {  
     i f   ( a . e m p t y ( )   | |   b . e m p t y ( ) )   {  
         r e t u r n   { } ;  
     }  
     i f   ( m i n ( a . s i z e ( ) ,   b . s i z e ( ) )   <   1 5 0 )   {  
         v e c t o r < M o d u l a r < T > >   c ( a . s i z e ( )   +   b . s i z e ( )   -   1 ,   0 ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   ( i n t )   a . s i z e ( ) ;   i + + )   {  
             f o r   ( i n t   j   =   0 ;   j   <   ( i n t )   b . s i z e ( ) ;   j + + )   {  
                 c [ i   +   j ]   + =   a [ i ]   *   b [ j ] ;  
             }  
         }  
         r e t u r n   c ;  
     }  
     r e t u r n   N T T < T > : : m u l t i p l y ( a ,   b ) ;  
 }  
  
 t e m p l a t e   < t y p e n a m e   T >  
 v e c t o r < M o d u l a r < T > > &   o p e r a t o r * = ( v e c t o r < M o d u l a r < T > > &   a ,   c o n s t   v e c t o r < M o d u l a r < T > > &   b )   {  
     r e t u r n   a   =   a   *   b ;  
 } 